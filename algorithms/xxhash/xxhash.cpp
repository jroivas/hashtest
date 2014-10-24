#include <algorithm.hh>
#include "xxhash.h"


std::string hashtest(std::string data)
{
    unsigned int res = XXH32(data.c_str(), data.length(), 0);
    return toString<unsigned int>(&res, sizeof(res));
}
