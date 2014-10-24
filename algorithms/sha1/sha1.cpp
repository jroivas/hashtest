#include <algorithm.hh>
#include <openssl/sha.h>
#include <string.h>

std::string hashtest(std::string data)
{
    unsigned char hash[SHA_DIGEST_LENGTH];
    memset(hash, 0, SHA_DIGEST_LENGTH);
    SHA1((const unsigned char*)(data.c_str()), data.size(), hash);

    std::string outp;
    for (unsigned int i = 0; i < SHA_DIGEST_LENGTH; ++i) {
        outp.push_back(hash[i]);
    }

    return outp;
}
