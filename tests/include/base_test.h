#pragma once

#include <string>
#include <functional>
#include <vector>
#include <map>
#include <ostream>
#include <initializer_list>
#include "termcolor.h"

std::string stringify(int value);
std::string stringify(std::initializer_list<int>);
std::string stringify(std::vector<int>);

class BaseFailure {
public:
    virtual ~BaseFailure() {}
    virtual void report() const;

protected:
    std::string description;
    std::string call;
    std::string initial;
    std::string expected;
    std::string actual;

    BaseFailure(const BaseFailure& fail);
    BaseFailure(const char* description, std::string call, std::string initial, std::string expected, std::string actual);
};

class BaseTestSuite {
public:
    virtual ~BaseTestSuite();
    virtual void setUp() = 0;
    virtual void tearDown() = 0;
    virtual void initialize(std::initializer_list<int>) = 0;

    virtual void test(std::string key, std::function<void()> function);
    virtual int run(std::string key="");
    virtual void report();

protected:
    std::map<std::string , std::vector<std::function<void()>>> tests;
    std::vector<BaseFailure*> failures;
    // Latest return value
    int* retval;
    // String representation of the function call with arguments
    std::string call;
};

