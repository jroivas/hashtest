#pragma once
#include <vector>
#include <map>
#include <functional>

class Suite
{
public:
    Suite() {}

    inline void addTest(
        std::string name,
        std::function<std::string (std::string)> entry)
    {
        m_tests[name] = entry;
    }

    void run(std::vector<std::string> data);
    std::map<std::string, unsigned long> collisions();
    unsigned long collisions(std::string name);
    double timing(std::string name);
    inline std::map<std::string, double> timing() const {
        return m_timing;
    }

    void printResults();

protected:
    unsigned int collisionsInDataSet(std::vector<std::string> data);
    std::map<
        std::string,
        std::function<std::string (std::string)>
    > m_tests;
    std::map<std::string, std::vector<std::string>> m_results;
    std::map<std::string, double> m_timing;
};
