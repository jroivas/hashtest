#include "suite.hh"

void Suite::run(std::vector<std::string> data)
{
    for (auto fn : m_tests) {
        for (auto line : data) {
            std::string res = fn(line);
        }
    }
}
