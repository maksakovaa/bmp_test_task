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
        BitMapHandler bmpHandler(argv[argc - 1]);
    }
    
    return 0;
}
