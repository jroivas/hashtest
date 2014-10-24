#include "suite.hh"
#include <iostream>
#include <algorithm>

void Suite::run(std::vector<std::string> data)
{
    for (auto fn : m_tests) {
        std::vector<std::string> res;
        for (auto line : data) {
            res.push_back(fn.second(line));
        }
        m_results[fn.first] = res;
    }
}

unsigned int Suite::collisionsInDataSet(std::vector<std::string> data)
{
    unsigned int coll = 0;

    std::sort(data.begin(), data.end());
    for (unsigned int i = 0; i < data.size() - 1; ++i) {
        coll += (data[i] == data[i+1]);
    }
    return coll;
}

std::map<std::string, unsigned long> Suite::collisions()
{
    std::map<std::string, unsigned long> res;
    for (auto entry : m_results) {
        res[entry.first] = collisionsInDataSet(entry.second);
    }
    return res;
}

unsigned long Suite::collisions(std::string name)
{
    auto entry = m_results.find(name);
    if (entry == m_results.end())
        throw std::string("Invalid result entry: " + name);

    return collisionsInDataSet(entry->second);
}

void Suite::printResults()
{
    for (auto set : m_results) {
        for (auto res : set.second) {
            std::cout << res << "\n";
        }
    }
}
