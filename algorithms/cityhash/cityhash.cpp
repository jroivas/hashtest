#include <algorithm.hh>
#include "city.h"

std::string hashtest(std::string data)
{
    uint64_t res = CityHash64(data.c_str(), data.length());
    return toString<uint64_t>(&res, sizeof(res));
}
