#include <algorithm.hh>

uint32_t jenkins_one_at_a_time_hash(const char *key, size_t len)
{
    uint32_t hash, i;
    for(hash = i = 0; i < len; ++i)
    {
        hash += key[i];
        hash += (hash << 10);
        hash ^= (hash >> 6);
    }
    hash += (hash << 3);
    hash ^= (hash >> 11);
    hash += (hash << 15);
    return hash;
}

std::string hashtest(std::string data)
{
    uint32_t res = jenkins_one_at_a_time_hash(data.c_str(), data.size());
    return toString<uint32_t>(&res, sizeof(res));
}
