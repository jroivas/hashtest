#include "suite.hh"
#include <iostream>

void Suite::run(std::vector<std::string> data)
{
    for (auto fn : m_tests) {
        std::vector<std::string> res;
        for (auto line : data) {
            res.push_back(fn(line));
        }
        m_results.push_back(res);
    }
}

void Suite::printResults()
{
    for (auto set : m_results) {
        for (auto res : set) {
            std::cout << res << "\n";
        }
    }
}
