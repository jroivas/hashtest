#include <algorithm.hh>

unsigned long
hash(const char *str)
{
    unsigned long hash = 5381;
    int c;

    while (c = *str++)
        hash = ((hash << 5) + hash) ^ c; /* hash * 33 ^ c */

    return hash;
}

std::string hashtest(std::string data)
{
    unsigned long res = hash(data.c_str());

    std::string outp;
    outp.push_back((char)(res & 0xFF));
    outp.push_back((char)(res >> 8) & 0xFF);
    outp.push_back((char)(res >> 16) & 0xFF);
    outp.push_back((char)(res >> 24) & 0xFF);

    return outp;
}
