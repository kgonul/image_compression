//
// Created by Kadir Gönül on 2020-04-23.
//

#ifndef UNTITLED1_IMAGE_MANAGER_H
#define UNTITLED1_IMAGE_MANAGER_H
#include <map>
#include <stdlib.h>
#include <stdio.h>
#include <png.h>

class image_manager {
public:
    std::map<unsigned char, int> dataRed, dataGreen, dataBlue;
    void readPngFile(const std::string& fileName);
    void writePngFile (std::string filename, std::string rawImageBuffer, int image_width, int image_height);
    void printPixelInfo();
    unsigned char *raw_image[3];
    int raw_image_size;
    int image_width;
    int image_height;

private:
    void process_png_file();
    png_bytep *row_pointers = NULL;
};


#endif //UNTITLED1_IMAGE_MANAGER_H
