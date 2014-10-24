#include <algorithm.hh>
#include <openssl/sha.h>
#include <string.h>

std::string hashtest(std::string data)
{
    unsigned char hash[SHA_DIGEST_LENGTH];
    memset(hash, 0, SHA_DIGEST_LENGTH);
    SHA1((const unsigned char*)(data.c_str()), data.size(), hash);

    return toString<unsigned char>((unsigned char*)hash, SHA_DIGEST_LENGTH);
}
