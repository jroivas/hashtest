#include <algorithm.hh>

unsigned long hash(std::string data)
{
    unsigned long hash = 2166136261UL;
    unsigned long prime = 16777619UL;
    for (auto octet : data)
        hash = (hash * prime) ^ (unsigned char)octet;

    return hash;
}

std::string hashtest(std::string data)
{
    unsigned long res = hash(data);
    return toString<unsigned long>(&res, sizeof(res));
}
