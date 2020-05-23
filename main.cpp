#include <iostream>
#include "huffman.h"
#include "image_manager.h"
#include "util.h"

const static string inputFileName = "lena.png";
const static string compressedFileName = "compressed_file.dc";

int main() {
    image_manager im;
    //Read png file and set frequencies for each symbol seperatedly for color channels
    im.readPngFile(inputFileName);

    //Generate huffman codes and later canonical huffman codes for each color channel
    huffman imHuffmanRed(im.dataRed);
    huffman imHuffmanGreen(im.dataGreen);
    huffman imHuffmanBlue(im.dataBlue);

    //Get encoded bit string for each color channel
    string encodedStrRed = imHuffmanRed.getEncodedData(im.raw_image[0], im.raw_image_size);
    string encodedStrGreen = imHuffmanGreen.getEncodedData(im.raw_image[1], im.raw_image_size);
    string encodedStrBlue = imHuffmanBlue.getEncodedData(im.raw_image[2], im.raw_image_size);

    //Convert bit string to hex data stream for each color channel
    std::string outputRed = BitStringToByteStream(encodedStrRed);
    std::string outputGreen = BitStringToByteStream(encodedStrGreen);
    std::string outputBlue = BitStringToByteStream(encodedStrBlue);

    /**
     * Generate header information for each color channel
     * Header structure as follows:
     * [Total symbol count] [Symbol]+ [Symbol length]+
     */
    std::string headerRed = imHuffmanRed.generateHeader();
    std::string headerGreen = imHuffmanGreen.generateHeader();
    std::string headerBlue = imHuffmanBlue.generateHeader();
    string headers = headerRed + headerGreen + headerBlue;

    /**
     * Write compressed data to file
     * Data structure as follows:
     * [Header] [Image width] [Image height] [Encoded data length]+ [Encoded data]+
     */
    WriteToFile(compressedFileName, headers, im.image_width, im.image_height, outputRed, outputGreen, outputBlue);

    std::map<unsigned char, int> symbols[3];
    std::string compressedData[3];
    int image_width, image_height;
    /**
     * Read compressed data from file
     * Separate symbols, compressed data, image width and image height
     */
    ReadFromFile(compressedFileName, symbols, compressedData, image_width, image_height);

    //Generate canonical codes from huffman codes for each color channel
    imHuffmanRed.regenerateCanonicalCodes(symbols[0]);
    imHuffmanGreen.regenerateCanonicalCodes(symbols[1]);
    imHuffmanBlue.regenerateCanonicalCodes(symbols[2]);

    //Generate bit string from compressed binary data for each color channel
    string compressedRedEncodedStr = ByteStreamToBitString(compressedData[0]);
    string compressedGreenEncodedStr = ByteStreamToBitString(compressedData[1]);
    string compressedBlueEncodedStr = ByteStreamToBitString(compressedData[2]);

    //Decode bit string for each color channel using regenerated canonical huffman codes
    string decodedRedString = imHuffmanRed.decodeData(compressedRedEncodedStr);
    string decodedGreenString = imHuffmanGreen.decodeData(compressedGreenEncodedStr);
    string decodedBlueString = imHuffmanBlue.decodeData(compressedBlueEncodedStr);


    string rawImageBuffer = ConcatComponents(decodedRedString, decodedGreenString, decodedBlueString);

    //Generate original image using libpng library
    std::string fileName = "regenerated_" +inputFileName;
    im.writePngFile(fileName, rawImageBuffer, image_width, image_height);

    return 0;
}