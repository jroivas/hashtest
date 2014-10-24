#include <algorithm.hh>
#include <string>
#include <functional>


std::string hashtest(std::string data)
{
    std::hash<std::string> hash_fn;
    unsigned long res = hash_fn(data);
    return toString<unsigned long>(&res, sizeof(res));
}
