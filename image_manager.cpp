//
// Created by Kadir Gönül on 2020-04-23.
//

#include <cstdio>
#include <iostream>
#include "image_manager.h"

#define NUM_OF_COMPONENTS 3

void image_manager::readPngFile(const std::string& fileName) {
    png_byte color_type;
    png_byte bit_depth;

    FILE *fp = fopen(fileName.c_str(), "rb");

    png_structp png = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
    if(!png) abort();

    png_infop info = png_create_info_struct(png);
    if(!info) abort();

    if(setjmp(png_jmpbuf(png))) abort();

    png_init_io(png, fp);

    png_read_info(png, info);

    image_width      = png_get_image_width(png, info);
    image_height     = png_get_image_height(png, info);
    color_type = png_get_color_type(png, info);
    bit_depth  = png_get_bit_depth(png, info);

    if(bit_depth == 16)
        png_set_strip_16(png);

    if(color_type == PNG_COLOR_TYPE_PALETTE)
        png_set_palette_to_rgb(png);

    // PNG_COLOR_TYPE_GRAY_ALPHA is always 8 or 16bit depth.
    if(color_type == PNG_COLOR_TYPE_GRAY && bit_depth < 8)
        png_set_expand_gray_1_2_4_to_8(png);

    if(png_get_valid(png, info, PNG_INFO_tRNS))
        png_set_tRNS_to_alpha(png);

    // These color_type don't have an alpha channel then fill it with 0xff.
    if(color_type == PNG_COLOR_TYPE_RGB ||
       color_type == PNG_COLOR_TYPE_GRAY ||
       color_type == PNG_COLOR_TYPE_PALETTE)
        png_set_filler(png, 0xFF, PNG_FILLER_AFTER);

    if(color_type == PNG_COLOR_TYPE_GRAY ||
       color_type == PNG_COLOR_TYPE_GRAY_ALPHA)
        png_set_gray_to_rgb(png);

    png_read_update_info(png, info);

    if (row_pointers) abort();

    row_pointers = (png_bytep*)malloc(sizeof(png_bytep) * image_height);
    for(int y = 0; y < image_height; y++) {
        row_pointers[y] = (png_byte*)malloc(png_get_rowbytes(png,info));
    }

    png_read_image(png, row_pointers);

    fclose(fp);

    png_destroy_read_struct(&png, &info, NULL);

    process_png_file();
}

void image_manager::process_png_file() {
    unsigned long location = 0;
    int i = 0;

    for(int i = 0; i<NUM_OF_COMPONENTS;i++) {
        raw_image[i] = (unsigned char*)malloc( image_width*image_height );
    }
    raw_image_size = image_width*image_height;

    for(int y = 0; y < image_height; y++) {
        png_bytep row = row_pointers[y];
        for(int x = 0; x < image_width; x++) {
            png_bytep px = &(row[x * 4]);
            //printf("%4d, %4d = RGBA(%3d, %3d, %3d, %3d)\n", x, y, px[0], px[1], px[2], px[3]);

            for(int j = 0; j<NUM_OF_COMPONENTS;j++) {
                raw_image[j][location] = px[j];
            }
            location++;

            //Calculate frequencies for each symbol
            dataRed[px[0]]++;
            dataGreen[px[1]]++;
            dataBlue[px[2]]++;
        }
    }
}

void image_manager::writePngFile(std::string filename, std::string rawImageBuffer, int image_width, int image_height) {
    int y;

    row_pointers = (png_bytep*)malloc(sizeof(png_bytep) * image_height);
    for(int y = 0; y < image_height; y++) {
        row_pointers[y] = (png_byte*)malloc(sizeof(png_byte) * image_width * 4);
    }

    for(int y = 0; y < image_height; y++) {
        png_bytep row = row_pointers[y];
        for(int x = 0; x < image_width; x++) {
            png_bytep px = &(row[x * 4]);
            int offset = y*image_width*NUM_OF_COMPONENTS+(x * NUM_OF_COMPONENTS);
            px[0] = rawImageBuffer[offset];
            px[1] = rawImageBuffer[offset+1];
            px[2] = rawImageBuffer[offset+2];
            px[3] = 0xff;
        }
    }

    FILE *fp = fopen(filename.c_str(), "wb");
    if(!fp) abort();

    png_structp png = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
    if (!png) abort();

    png_infop info = png_create_info_struct(png);
    if (!info) abort();

    if (setjmp(png_jmpbuf(png))) abort();

    png_init_io(png, fp);

    // Output is 8bit depth, RGBA format.
    png_set_IHDR(
            png,
            info,
            image_width, image_height,
            8,
            PNG_COLOR_TYPE_RGBA,
            PNG_INTERLACE_NONE,
            PNG_COMPRESSION_TYPE_DEFAULT,
            PNG_FILTER_TYPE_DEFAULT
    );
    png_write_info(png, info);

    // To remove the alpha channel for PNG_COLOR_TYPE_RGB format,
    // Use png_set_filler().
    //png_set_filler(png, 0, PNG_FILLER_AFTER);

    if (!row_pointers) abort();

    png_write_image(png, row_pointers);
    png_write_end(png, NULL);

    for(int y = 0; y < image_height; y++) {
        free(row_pointers[y]);
    }
    free(row_pointers);

    fclose(fp);

    png_destroy_write_struct(&png, &info);
}
