#include <algorithm.hh>
#include <cstdint>
#include "MurmurHash2.h"

std::string hashtest(std::string data)
{
    uint32_t res = MurmurHash2(data.c_str(), data.length(), 0);
    return toString<uint32_t>(&res, sizeof(res));
}
