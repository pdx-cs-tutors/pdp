#include <sstream>
#include "../include/cll_test.h"

// Helper function to create a string representing a CLL given its rear node
// e.g. "[1 -> 2 -> 3]"
std::string stringify(cll::node* rear) {
    if (!rear) return "[]";
    cll::node* current = rear->next;
    std::stringstream ss;
    ss << "[";
    if (rear->next == rear) {
        ss << rear->data << "]";
        return ss.str();
    }
    do {
        ss << current->data;
        if (current->next != rear) ss << " -> ";
        current = current->next;
    } while (current != rear);
    ss << " -> " << rear->data << "]";
    return ss.str();
}

// Helper function to deallocate CLL memory during tests
void destroy_cll(cll::node*& rear) {
    if (rear == nullptr) return;
    cll::node* curr = rear;
    while (curr->next != rear) {
        cll::node* temp = curr->next;
        curr->next = temp->next;
        delete temp;
        temp = nullptr;
    }
    delete rear;
    rear = nullptr;
}

///////////////
// CLL FAILURES
///////////////

CLLFailure::CLLFailure(const char* description,
                       std::string call,
                       std::vector<int>& initial,
                       std::initializer_list<int> expected,
                       cll::node* actual)
    : BaseFailure(description, call, stringify(initial), stringify(expected), stringify(actual)) {

};

CLLFailure::CLLFailure(const CLLFailure& fail) : BaseFailure(fail) {
}

CLLReturnFailure::CLLReturnFailure(const char* description,
                                   std::string call,
                                   std::vector<int>& initial,
                                   int expected,
                                   int actual)
    : BaseFailure(description, call, stringify(initial), stringify(expected), stringify(actual)) {
}

CLLReturnFailure::CLLReturnFailure(const CLLReturnFailure& fail) : BaseFailure(fail) {
}

//////////////////
// CLL TEST SUITES
//////////////////

void CLLTestSuite::setUp() {
    BaseTestSuite::setUp();
    rear = nullptr;
    initial = {};
}

void CLLTestSuite::tearDown() {
    BaseTestSuite::tearDown();
    if (rear) destroy_cll(rear);
    rear = nullptr;
    initial = {};
}

// Fill the CLL under test with the given values
// e.g. initialize({1, 2, 3});
void CLLTestSuite::initialize(std::initializer_list<int> values) {
    rear = nullptr;
    for (auto it = values.end(); it != values.begin();) {
        if (!rear) {
            rear = new cll::node();
            rear->data = *--it;
            rear->next = rear;
        } else {
            cll::node* temp = rear->next;
            rear->next = new cll::node();
            rear->next->data = *--it;
            rear->next->next = temp;
        }
    }
    initial = values;
}

// Verify that the nodes in the CLL under test match the given values
// e.g. expectList({1, 2, 3});
// Add failures if there are discrepancies
void CLLTestSuite::expectList(std::initializer_list<int> values) {
    if (!rear && values.size() > 0) {
        addFailure(CLLFailure(
            "Missing item(s)",
            call,
            initial,
            values,
            rear
        ));
        return;
    }
    if (values.size() == 0) {
        if (rear) {
            addFailure(CLLFailure(
                "Too many items",
                call,
                initial,
                values,
                rear
            ));
        } else return;
    }
    cll::node* curr = rear->next;
    int count = 0;
    for (auto value : values) {
        if (curr->data != value) {
            addFailure(CLLFailure(
                "Incorrect value(s)",
                call,
                initial,
                values,
                rear
            ));
            return;
        }
        ++count;
        curr = curr->next;
    }
    if (curr != rear->next) {
        addFailure(CLLFailure(
            "Too many items",
            call,
            initial,
            values,
            rear
        ));
    }
}

// Verify that a CLL function has returned the expected value
// e.g. expectReturn(1);
// Add failure if retval does not match
void CLLTestSuite::expectReturn(int value) {
    if (retval == nullptr || *retval != value) {
        addFailure(CLLReturnFailure(
            "Incorrect return value",
            call,
            initial,
            value,
            *retval
        ));
    }
}

void CLLTestSuite::addFailure(const CLLFailure& fail) {
    failures.push_back(new CLLFailure(fail));
}

void CLLTestSuite::addFailure(const CLLReturnFailure& fail) {
    failures.push_back(new CLLReturnFailure(fail));
}

