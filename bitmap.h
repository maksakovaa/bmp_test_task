#pragma once

#include "bmp_struct.h"

#include <fstream>
#include <string>
#include <iostream>
#include <vector>

class BitMapHandler
{
public:
    BitMapHandler(const std::string& fileName);
    ~BitMapHandler();
private:
    void openBMP(const std::string& fileName);
    void displayBMP();
    void closeBMP();
    unsigned char bitextract(const unsigned int byte, const unsigned int mask);
    std::ifstream bitmap;
    BitmapFileHeader m_header;
    BitmapInfoHeader m_info;
    std::vector<std::string> image;
};
