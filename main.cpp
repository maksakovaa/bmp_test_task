#include "bitmap.h"
#include <iostream>

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cout << "Usage: " << argv[0] << " path_to_file" <<  std::endl;
        return 0;
    }
    else
    {
        BitMapHandler bmpHandler;
        bmpHandler.openBMP(argv[argc - 1]);
        bmpHandler.displayBMP();
        bmpHandler.closeBMP();
    }
    
    return 0;
}
