#pragma once
#include <vector>
#include <functional>

class Suite
{
public:
    Suite() {}

    inline void addTest(std::function<std::string (std::string)> entry) {
        m_tests.push_back(entry);
    }

    void run(std::vector<std::string> data);

    void printResults();
    std::vector<std::vector<std::string>> m_results;

protected:
    std::vector<std::function<std::string (std::string)>> m_tests;
};
