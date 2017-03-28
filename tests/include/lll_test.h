#pragma once
#include "base_test.h"
#include "../../include/lll.h"

///////////////
// LLL FAILURES
///////////////

// Represents a failure when the values in an LLL are incorrect.
class LLLFailure : public BaseFailure {
public:
    LLLFailure(const char* description, std::string call, std::vector<int>& initial, std::initializer_list<int> expected, lll::node* actual);
    LLLFailure(const LLLFailure& fail);
};

// Represents a failure when an LLL function returns the wrong value.
class LLLReturnFailure : public BaseFailure {
public:
    LLLReturnFailure(const char* description, std::string call, std::vector<int>& initial, int expected, int actual);
    LLLReturnFailure(const LLLReturnFailure& fail);
};

//////////////////
// LLL TEST SUITES
//////////////////

// Base suite of LLL tests
// All LLL test suites extend this class
class LLLTestSuite: public BaseTestSuite {
public:
    virtual ~LLLTestSuite();
    void setUp();
    void tearDown();
    void initialize(std::initializer_list<int> values);
    void expectList(std::initializer_list<int> values);
    void expectReturn(int value);
    void addFailure(const LLLFailure& fail);
    void addFailure(const LLLReturnFailure& fail);

protected:
    // This class should not be instantiated - use a subclass
    LLLTestSuite() {};
    // Head of the list under test
    lll::node* head;
    // Initial list values
    std::vector<int> initial;
};

// Classes below contain the actual tests
// One class per file in /tests/lll/*.cpp

// Insertion tests
class LLLInsertionTests : public LLLTestSuite {
public:
    LLLInsertionTests();
    virtual ~LLLInsertionTests() {};
};

// Removal tests
class LLLRemovalTests : public LLLTestSuite {
public:
    LLLRemovalTests();
    virtual ~LLLRemovalTests() {};
};
