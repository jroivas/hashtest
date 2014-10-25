#include <iostream>
#include <fstream>
#include <algorithm>
#include "testloader.hh"
#include "suite.hh"

void usage(std::string appname)
{
    std::cout << "Usage: " << appname << " data_file algorithm [algorithm2]\n";
}

std::vector<std::string> readData(std::string f)
{
    std::vector<std::string> res;
    std::ifstream datafile(f);
    if (datafile.is_open()) {
        std::string line;
        while (getline(datafile, line)) {
            if (!line.empty())
                res.push_back(line);
        }
    }
    datafile.close();
    return res;
}

template<typename A, typename B>
std::pair<B, A> flip_pair(const std::pair<A, B> &data)
{
    return std::pair<B, A>(data.second, data.first);
}

template<typename A, typename B>
std::multimap<B, A> flip_map(const std::map<A, B> &src)
{
    std::multimap<B, A> res;
    std::transform(
        src.begin(), src.end(),
        std::inserter(res, res.begin()),
        flip_pair<A, B>);
    return res;
}

int main(int argc, char **argv)
{
    if (argc < 3) {
        usage(argv[0]);
        return 1;
    }

    std::vector<std::string> data = readData(argv[1]);

    Suite suite;
    std::vector<Test*> tests;
    for (int p = 2; p < argc; ++p) {
        Test *test = TestLoader::load(argv[p]);
        if (test != nullptr) {
            std::cout << "Adding " << argv[p] << "\n";
            tests.push_back(test);
            suite.addTest(argv[p], test->func());
        } else {
            std::cerr << "ERROR: Can't load " << argv[p] << "\n";
            return 1;
        }
    }

    suite.run(data);

    std::map<std::string, unsigned long> coll = suite.collisions();
    std::multimap<unsigned long, std::string> coll_rev = flip_map(coll);
    std::map<std::string, double> timings = suite.timing();
    std::multimap<double, std::string> timings_rev = flip_map(timings);

    for (int p = 2; p < argc; ++p) {
        std::string item = argv[p];
        std::cout << item << ":\n";

        std::cout << "  " << coll[item] << " collisions\n";
        std::cout << "  " << timings[item] << " nanoseconds per item\n";
    }

    std::cout << "From fastest to slowest:";
    for (auto item : timings_rev) {
        std::cout << " " << item.second;
    }
    std::cout << "\n";

    std::cout << "From best to worst     :";
    for (auto item : coll_rev) {
        std::cout << " " << item.second;
    }
    std::cout << "\n";

    for (auto test : tests) {
        delete test;
    }

    return 0;
}
