#include <iostream>
#include <sstream>
#include "tests/include/lll_test.h"
#include "tests/include/cll_test.h"

void print_no_match(std::string message) {
    std::cerr << termcolor::magenta << "Error: " << termcolor::reset;
    std::cerr << "Couldn't find any tests matching "
              << termcolor::bold << message << termcolor::reset << std::endl;
}

int main(int argc, char **argv) {
    std::map<std::string, std::map<std::string, BaseTestSuite*>> suites;

    suites["lll"] = {
        {"insertion", new LLLInsertionTests()},
        {"removal", new LLLRemovalTests()}
    };

    suites["cll"] = {
        {"insertion", new CLLInsertionTests()},
        {"removal", new CLLRemovalTests()}
    };

    int errored = 0;

    if (argc == 1 || strcmp(argv[1], "all") == 0) {
        for (auto suite : suites) {
            for (auto set : suite.second) {
                set.second->run();
            }
        }
    } else if (argc == 2) {
        auto it = suites.find(argv[1]);
        if (it == suites.end()) {
            print_no_match(argv[1]);
            errored = 1;
        } else {
            for (auto set : suites[argv[1]]) {
                set.second->run();
            }
        }
    } else if (argc > 2) {
        auto it = suites[argv[1]].find(argv[2]);
        if (it == suites[argv[1]].end()) {
            std::stringstream ss;
            ss << argv[1] << " " << argv[2];
            print_no_match(ss.str());
            errored = 1;
        } else {
            if (argc > 3) {
                if (!suites[argv[1]][argv[2]]->run(argv[3])) {
                    std::stringstream ss;
                    ss << argv[1] << " " << argv[2] << " " << argv[3];
                    print_no_match(ss.str());
                }
            } else {
                suites[argv[1]][argv[2]]->run();
            }
        }
    }

    for (auto const& pair : suites) {
        for (auto const& suite : suites[pair.first]) {
            if (suite.second) delete suite.second;
        }
    }

    return errored;
}
