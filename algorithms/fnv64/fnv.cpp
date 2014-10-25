#include <algorithm.hh>

unsigned long long hash(std::string data)
{
    unsigned long long hash = 14695981039346656037ULL;
    unsigned long long prime = 1099511628211ULL;
    for (auto octet : data)
        hash = (hash * prime) ^ octet;

    return hash;
}

std::string hashtest(std::string data)
{
    unsigned long long res = hash(data);
    return toString<unsigned long long>(&res, sizeof(res));
}
