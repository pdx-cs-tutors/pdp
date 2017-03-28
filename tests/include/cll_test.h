#pragma once
#include "base_test.h"
#include "../../include/cll.h"

///////////////
// CLL FAILURES
///////////////

// Represents a failure when the values in a CLL are incorrect.
class CLLFailure : public BaseFailure {
public:
    CLLFailure(const char* description, std::string call, std::vector<int>& initial, std::initializer_list<int> expected, cll::node* actual);
    CLLFailure(const CLLFailure& fail);
};

// Represents a failure when a CLL function returns the wrong value.
class CLLReturnFailure : public BaseFailure {
public:
    CLLReturnFailure(const char* description, std::string call, std::vector<int>& initial, int expected, int actual);
    CLLReturnFailure(const CLLReturnFailure& fail);
};

//////////////////
// CLL TEST SUITES
//////////////////

// Base suite of CLL tests
// All CLL test suites extend this class
class CLLTestSuite : public BaseTestSuite {
public:
    virtual ~CLLTestSuite() {};
    void setUp();
    void tearDown();
    void initialize(std::initializer_list<int> values);
    void expectList(std::initializer_list<int> values);
    void expectReturn(int value);
    void addFailure(const CLLFailure& fail);
    void addFailure(const CLLReturnFailure& fail);

protected:
    // This class should not be instantiated - use a subclass
    CLLTestSuite() {};
    // Rear of the list under test
    cll::node* rear;
    // Initial list values
    std::vector<int> initial;
};

// Classes below contain the actual tests
// One class per file in /tests/cll/*.cpp

// Insertion tests
class CLLInsertionTests : public CLLTestSuite {
public:
    CLLInsertionTests();
    virtual ~CLLInsertionTests() {};
};

// Removal tests
class CLLRemovalTests : public CLLTestSuite {
public:
    CLLRemovalTests();
    virtual ~CLLRemovalTests() {};
};
