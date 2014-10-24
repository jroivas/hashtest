#include <algorithm.hh>
#include <cstdint>
#include "MurmurHash2.h"

std::string hashtest(std::string data)
{
    uint32_t res = MurmurHash2(data.c_str(), data.length(), 0);

    std::string outp;
    outp.push_back((char)(res & 0xFF));
    outp.push_back((char)(res >> 8) & 0xFF);
    outp.push_back((char)(res >> 16) & 0xFF);
    outp.push_back((char)(res >> 24) & 0xFF);

    return outp;
}
