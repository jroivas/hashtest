#include <algorithm.hh>
#include "../xxhash/xxhash.h"


std::string hashtest(std::string data)
{
    unsigned long long res = XXH64(data.c_str(), data.length(), 0);
    return toString<unsigned long long>(&res, sizeof(res));
}
