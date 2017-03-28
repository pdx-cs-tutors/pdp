#include <iostream>
#include <sstream>
#include "include/base_test.h"

std::string stringify(int value) {
    std::stringstream ss;
    ss << value;
    return ss.str();
}

std::string stringify(std::vector<int> values) {
    std::stringstream ss;
    ss << "[";
    if (values.size() > 0) {
        std::copy(values.begin(), values.end() - 1, std::ostream_iterator<int>(ss, " -> "));
        ss << *(values.end() - 1);
    }
    ss << "]";
    return ss.str();
}

std::string stringify(std::initializer_list<int> values) {
    std::stringstream ss;
    ss << "[";
    if (values.size() > 0) {
        std::copy(values.begin(), values.end() - 1, std::ostream_iterator<int>(ss, " -> "));
        ss << *(values.end() - 1);
    }
    ss << "]";
    return ss.str();
}


void BaseFailure::report() const {
    std::cout << termcolor::on_red << termcolor::bold << " FAILED " << termcolor::reset
              << " " << description << std::endl
              << "Initial:  " << initial << std::endl
              << "Called:   " << termcolor::bold << call << termcolor::reset << std::endl
              << "Expected: " << expected << std::endl
              << "Got:      " << actual << std::endl;
}

BaseFailure::BaseFailure(const BaseFailure& fail) : description(fail.description), call(fail.call), initial(fail.initial), expected(fail.expected), actual(fail.actual) {
}

BaseFailure::BaseFailure(const char* description, std::string call, std::string initial, std::string expected,
                         std::string actual) : description(description), call(call), initial(initial), expected(expected), actual(actual) {
}

void BaseTestSuite::report() {
    for (auto const* fail : failures) {
        fail->report();
        std::cout << std::endl;
    }
}

void BaseTestSuite::setUp() {
    retval = nullptr;
}

void BaseTestSuite::tearDown() {
    if (retval) delete retval;
    retval = nullptr;
}

int BaseTestSuite::run(std::string key) {
    int count = 0;
    if (key != "") {
        auto it = tests.find(key);
        if (it != tests.end()) {
            for (auto const& func: tests[key]) {
                setUp();
                func();
                tearDown();
                ++count;
            }
        }
    } else {
        for (auto const& test : tests) {
            for (auto const& func : test.second) {
                setUp();
                func();
                tearDown();
                ++count;
            }
        }
    }
    report();
    return count;
}

void BaseTestSuite::test(std::string key, std::function<void()> function) {
    if (tests.find(key) == tests.end()) {
        std::vector<std::function<void()>> funcs = {function};
        tests.insert(std::make_pair(key, funcs));
    } else {
        tests[key].push_back(function);
    }
}

BaseTestSuite::~BaseTestSuite() {
    for (auto const* fail : failures) {
        if (fail) delete fail;
    }
}

