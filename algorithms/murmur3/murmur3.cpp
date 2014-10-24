#include <algorithm.hh>
#include <cstdint>
#include "MurmurHash3.h"

std::string hashtest(std::string data)
{
    uint32_t res;
    MurmurHash3_x86_32(data.c_str(), data.length(), 0, &res);
    return toString<uint32_t>(&res, sizeof(res));
}
