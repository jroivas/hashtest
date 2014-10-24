#include <iostream>
#include <fstream>
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
            res.push_back(line);
        }
    }
    datafile.close();
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
            suite.addTest(test->func());
        } else {
            std::cerr << "ERROR: Can't load " << argv[p] << "\n";
            return 1;
        }
    }

    suite.run(data);
    suite.printResults();

    for (auto test : tests) {
        delete test;
    }

    return 0;
}
