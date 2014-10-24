#include <algorithm.hh>
#include <string>
#include <functional>


std::string hashtest(std::string data)
{
    std::hash<std::string> hash_fn;
    unsigned long res = hash_fn(data);

    std::string outp;
    outp.push_back((char)(res & 0xFF));
    outp.push_back((char)(res >> 8) & 0xFF);
    outp.push_back((char)(res >> 16) & 0xFF);
    outp.push_back((char)(res >> 24) & 0xFF);

    return outp;
}
