#include <sstream>
#include "../include/lll_test.h"

// Helper function to create a string representing an LLL given its head node
// e.g. "[1 -> 2 -> 3]"
std::string stringify(lll::node* head) {
    std::stringstream ss;
    ss << "[";
    while (head) {
        ss << head->data;
        if (head->next) ss << " -> ";
        head = head->next;
    }
    ss << "]";
    return ss.str();
}

// Helper function to deallocate LLL memory during tests
void destroy_lll(lll::node* head) {
    while (head) {
        lll::node* temp = head->next;
        delete head;
        head = temp;
    }
}

///////////////
// LLL FAILURES
///////////////

LLLFailure::LLLFailure(const char* description,
                       std::string call,
                       std::vector<int>& initial,
                       std::initializer_list<int> expected,
                       lll::node* actual)
    : BaseFailure(description, call, stringify(initial), stringify(expected), stringify(actual)) {
}

LLLFailure::LLLFailure(const LLLFailure& fail) : BaseFailure(fail) {
}


LLLReturnFailure::LLLReturnFailure(const char* description,
                                   std::string call,
                                   std::vector<int>& initial,
                                   int expected,
                                   int actual)
    : BaseFailure(description, call, stringify(initial), stringify(expected), stringify(actual)){
}

LLLReturnFailure::LLLReturnFailure(const LLLReturnFailure& fail) : BaseFailure(fail) {
}

//////////////////
// CLL TEST SUITES
//////////////////

void LLLTestSuite::addFailure(const LLLFailure& fail) {
    failures.push_back(new LLLFailure(fail));
}

void LLLTestSuite::setUp() {
    head = nullptr;
    retval = nullptr;
    initial = {};
}

void LLLTestSuite::tearDown() {
    if (head) destroy_lll(head);
    head = nullptr;// Verify that the nodes in the LLL match the given values
// e.g. expectList(head, {1, 2, 3});
// Add failures if there are discrepancies
    if (retval) delete retval;
    retval = nullptr;
}

LLLTestSuite::~LLLTestSuite() {
}

// Verify that the nodes in the LLL under test match the given values
// e.g. expectList({1, 2, 3});
// Add failures if there are discrepancies
void LLLTestSuite::expectList(std::initializer_list<int> values) {
    lll::node* curr = head;
    int count = 0;
    for (auto value : values) {
        if (!curr) {
            addFailure(LLLFailure(
                "Missing item(s)",
                call,
                initial,
                values,
                head
            ));
            return;
        } else if (curr->data != value) {
            addFailure(LLLFailure(
                "Incorrect value(s)",
                call,
                initial,
                values,
                head
            ));
            return;
        }
        ++count;
        curr = curr->next;
    }
    if (curr) {
        addFailure(LLLFailure(
            "Too many items",
            call,
            initial,
            values,
            head
        ));
    }
}

// Verify that an LLL function has returned the expected value
// e.g. expectReturn(1);
// Add failure if retval does not match
void LLLTestSuite::expectReturn(int value) {
    if (retval == nullptr || *retval != value) {
        addFailure(LLLReturnFailure(
            "Incorrect return value",
            call,
            initial,
            value,
            *retval
        ));
    }
}

// Fill the LLL under test with the given values
// e.g. initialize({1, 2, 3});
void LLLTestSuite::initialize(std::initializer_list<int> values) {
    head = nullptr;
    for (auto it = values.end(); it != values.begin();) {
        lll::node* temp = head;
        head = new lll::node();
        head->data = *--it;
        head->next = temp;
    }
    initial = values;
}

void LLLTestSuite::addFailure(const LLLReturnFailure& fail) {
    failures.push_back(new LLLReturnFailure(fail));
}
