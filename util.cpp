//
// Created by Kadir Gönül on 2020-04-19.
//

#include "util.h"
#include <sstream>
#include <fstream>

std::string BitStringToByteStream(const std::string & str) {
    std::stringstream sstream(str);
    std::string output;
    while(sstream.good() && sstream.peek() != EOF) {
        std::bitset<8> bits;
        sstream >> bits;
        output += char(bits.to_ulong());
    }
    //Last byte holds previous byte size
    int lastByteBitSize = str.size() % 8;
    lastByteBitSize = (lastByteBitSize == 0) ? 8 : lastByteBitSize;
    output += (lastByteBitSize);
    return output;
}

std::string ByteStreamToBitString(std::string& str) {
    std::string binaryString = "";
    std::string temp = str;
    //Last byte holds previous byte size
    int lastByteBitSize = temp.back();
    temp.pop_back();
    for (char& _char : temp) {
        binaryString += std::bitset<8>(_char).to_string();
    }
    if (lastByteBitSize != 8) {
        binaryString.erase(binaryString.end()-8, binaryString.end()-lastByteBitSize);
    }

    return binaryString;
}

//3x[symbol count + each symbol and length] + image width + image height + 3x[compressed data length in integer + compressed data]
void WriteToFile(const std::string& fileName, const std::string& header, int &w, int &h,
                            const std::string& red, const std::string& green, const std::string& blue) {
    std::ofstream out(fileName, std::ios::binary);
    out << header;
    out.write((char*)&w,sizeof(w));
    out.write((char*)&h,sizeof(h));
    int size = red.size();
    out.write((char*)&size,sizeof(size));
    out<<red;
    size = green.size();
    out.write((char*)&size,sizeof(size));
    out<<green;
    size = blue.size();
    out.write((char*)&size,sizeof(size));
    out<<blue;
    out.close();
}

//3x[symbol count + each symbol and length] + image width + image height + 3x[compressed data length in integer + compressed data]
void ReadFromFile(const std::string& fileName, std::map<unsigned char, int> symbols[3], std::string compressedData[3], int &w, int &h) {
    int compressedDataSize=0;
    std::ifstream ifs(fileName, std::ios::binary);
    int symbolCount = ifs.get() + 1;
    for(int i=0;i<symbolCount;i++) {
        unsigned char x1 = ifs.get();
        int x2 = ifs.get();
        symbols[0][x1] = x2;
    }
    symbolCount = ifs.get() + 1;
    for(int i=0;i<symbolCount;i++) {
        unsigned char x1 = ifs.get();
        int x2 = ifs.get();
        symbols[1][x1] = x2;
    }

    symbolCount = ifs.get() + 1;
    for(int i=0;i<symbolCount;i++) {
        unsigned char x1 = ifs.get();
        int x2 = ifs.get();
        symbols[2][x1] = x2;
    }

    ifs.read((char*)&w,sizeof(w));
    ifs.read((char*)&h,sizeof(h));

    ifs.read((char*)&compressedDataSize,sizeof(compressedDataSize));
    for(int i=0;i<compressedDataSize;i++) {
        compressedData[0] += ifs.get();
    }
    ifs.read((char*)&compressedDataSize,sizeof(compressedDataSize));
    for(int i=0;i<compressedDataSize;i++) {
        compressedData[1] += ifs.get();
    }
    ifs.read((char*)&compressedDataSize,sizeof(compressedDataSize));
    for(int i=0;i<compressedDataSize;i++) {
        compressedData[2] += ifs.get();
    }
}

std::string ConcatComponents(std::string red, std::string green, std::string blue) {
    std::string str = "";
    for (int i = 0; i< red.size(); i++) {
        str += red[i];
        str += green[i];
        str += blue[i];
    }
    return str;
}