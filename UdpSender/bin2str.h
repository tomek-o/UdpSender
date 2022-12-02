#ifndef bin2strH
#define bin2strH

#include <System.hpp>
#include <time.h>
#ifdef __BORLANDC__
#  pragma pack(push, 8)
#endif
#include <string>
#ifdef __BORLANDC__
#  pragma pack(pop)
#endif

    int hexStringToInt (std::string);
    std::string intToHexString (int);
    int binStringToInt (std::string);
    std::string intToBinString (int);
    std::string HexStringToBuf(std::string);
    std::string BufToHexString(std::string);
    std::string BufToHexString(unsigned char* ptr, unsigned int size);

#endif

