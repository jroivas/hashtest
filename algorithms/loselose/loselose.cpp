#include <algorithm.hh>

unsigned long
hash(const char *str)
{
    unsigned int hash = 0;
    int c;

    while (c = *str++)
        hash += c;

    return hash;
}


std::string hashtest(std::string data)
{
    unsigned long res = hash(data.c_str());
    return toString<unsigned long>(&res, sizeof(res));
}
