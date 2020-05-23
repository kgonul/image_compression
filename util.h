//
// Created by Kadir Gönül on 2020-04-19.
//

#ifndef UNTITLED1_UTIL_H
#define UNTITLED1_UTIL_H

#include <iostream>
#include <map>

std::string BitStringToByteStream(const std::string & str);
std::string ByteStreamToBitString(std::string& str);
std::string ConcatComponents(std::string red, std::string green, std::string blue);

void WriteToFile(const std::string& fileName, const std::string& header, int &w, int &h,
        const std::string& red, const std::string& green, const std::string& blue);
void ReadFromFile(const std::string& fileName, std::map<unsigned char, int> symbols[3], std::string compressedData[3], int &w, int &h);

#endif //UNTITLED1_UTIL_H
