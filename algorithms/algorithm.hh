#include <string>
#include <iostream>

extern "C" {
    std::string hashtest(std::string data);
}

std::string toHexChar(char val)
{
    std::string res;
    if (val >= 0 && val < 10)
        res.push_back('0' + val);
    else if (val <= 0xf)
        res.push_back('a' + (val - 10));
    else
        throw std::string("Invalid char: " + val);

    return res;
}

template<typename T>
std::string toString(T* value, unsigned int size)
{
    std::string outp;
    unsigned int c = 0;
    char *ptr = (char*)value;

    while (c < size) {
        outp += toHexChar((*ptr >> 4) & 0xF);
        outp += toHexChar(*ptr & 0xF);
        ++ptr;
        ++c;
    }
    return outp;
}
