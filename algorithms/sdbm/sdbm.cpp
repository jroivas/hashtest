#include <algorithm.hh>

static unsigned long
sdbm(const char *str)
{
    unsigned long hash = 0;
    int c;

    while (c = *str++)
        hash = c + (hash << 6) + (hash << 16) - hash;

    return hash;
}

std::string hashtest(std::string data)
{
    unsigned long res = sdbm(data.c_str());
    return toString<unsigned long>(&res, sizeof(res));
}
