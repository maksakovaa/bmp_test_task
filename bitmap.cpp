#include "bitmap.h"

BitMapHandler::BitMapHandler(const std::string& fileName)
{
    openBMP(fileName);
    displayBMP();
}

BitMapHandler::~BitMapHandler()
{
    closeBMP();
}

void BitMapHandler::openBMP(const std::string &fileName)
{
    bitmap = std::ifstream(fileName, std::ios::binary);
    if (bitmap.is_open())
    {
        bitmap.read((char*)&m_header, sizeof(m_header));
        if (m_header.Type == BF_TYPE)
        {
            bitmap.read((char*)&m_info, sizeof(m_info));

            image.resize(m_info.Height);
            unsigned int bufer;
            int linePadding = ((m_info.Width * (m_info.BitCount / 8)) % 4) & 3;
            for (int i = m_info.Height - 1; i >= 0; i--)
            {
                image[i].resize(m_info.Width);
                unsigned int j = 0;
                while (j < m_info.Width)
                {
                    bitmap.read(reinterpret_cast<char*>(&bufer), m_info.BitCount / 8);
                    if (bitextract(bufer, m_info.RedMask) == 255 &&
                    bitextract(bufer, m_info.GreenMask) == 255 &&
                    bitextract(bufer, m_info.BlueMask == 255))
                    {
                        image[i][j] = ' ';
                    }
                    else
                    {
                        image[i][j] = '*';
                    }
                    j++;
                }
                bitmap.seekg(linePadding, std::ios_base::cur);               
            }
        }
        else
        {
            throw std::runtime_error("File " + fileName + " isn't bitmap image");
        }

    }   
}

void BitMapHandler::displayBMP()
{
    if (bitmap.is_open())
    {
        for (auto i : image)
        {
            std::cout << i << std::endl;
        }
    }
}

void BitMapHandler::closeBMP()
{
    if (bitmap.is_open())
    {
        bitmap.close();
        image.clear();
    }
}

unsigned char BitMapHandler::bitextract(const unsigned int byte, const unsigned int mask)
{
    if (mask == 0)
    {
        return 0;
    }

    int maskBufer = mask, maskPadding = 0;
 
    while (!(maskBufer & 1))
    {
        maskBufer >>= 1;
        maskPadding++;
    }
 
    return (byte & mask) >> maskPadding;
}