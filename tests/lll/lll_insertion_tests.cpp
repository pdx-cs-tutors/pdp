#include "../include/lll_test.h"

LLLInsertionTests::LLLInsertionTests() {
    test("append", [=] {
        call = "append(head, 1)";
        initialize({3, 2});
        append(head, 1);
        expectList({3, 2, 1});
    });
    test("append", [=] {
        call = "append(head, 1)";
        retval = new int(append(head, 1));
        expectList({1});
        expectReturn(1);
    });

    test("append_unique", [=] {
        call = "append_unique(1)";
        retval = new int(append_unique(head, 1));
        expectList({1});
        expectReturn(1);
    });
    test("append_unique", [=] {
        call = "append_unique(1)";
        initialize({4, 1, 8});
        retval = new int(append_unique(head, 1));
        expectList({4, 1, 8});
        expectReturn(0);
    });
    test("append_unique", [=] {
        call = "append_unique(5)";
        initialize({3, 2, 2});
        retval = new int(append_unique(head, 5));
        expectList({3, 2, 2, 5});
        expectReturn(1);
    });

    test("prepend", [=] {
        call = "prepend(head, 3)";
        initialize({2, 9, 0});
        retval = new int(prepend(head, 3));
        expectList({3, 2, 9, 0});
        expectReturn(1);
    });
    test("prepend", [=] {
        call = "prepend(head, 3)";
        retval = new int(prepend(head, 3));
        expectList({3});
        expectReturn(1);
    });

    test("prepend_unique", [=] {
        call = "prepend_unique(head, 2)";
        retval = new int(prepend_unique(head, 2));
        expectList({2});
        expectReturn(1);
    });
    test("prepend_unique", [=] {
        call = "prepend_unique(head, 2)";
        initialize({2});
        retval = new int(prepend_unique(head, 2));
        expectList({2});
        expectReturn(0);
    });
    test("prepend_unique", [=] {
        call = "prepend_unique(head, 2)";
        initialize({3, 4, 1});
        retval = new int(prepend_unique(head, 2));
        expectList({2, 3, 4, 1});
        expectReturn(1);
    });
    test("prepend_unique", [=] {
        call = "prepend_unique(head, 2)";
        initialize({9, 7, 2});
        retval = new int(prepend_unique(head, 2));
        expectList({9, 7, 2});
        expectReturn(0);
    });

    test("insert_ordered", [=] {
        call = "insert_ordered(head, 9)";
        initialize({1, 2, 4});
        retval = new int(insert_ordered(head, 9));
        expectList({1, 2, 4, 9});
        expectReturn(1);
    });
    test("insert_ordered", [=] {
        call = "insert_ordered(head, 9)";
        initialize({2, 9, 10});
        retval = new int(insert_ordered(head, 9));
        expectList({2, 9, 9, 10});
        expectReturn(1);
    });
    test("insert_ordered", [=] {
        call = "insert_ordered(head, 9)";
        initialize({10, 11});
        retval = new int(insert_ordered(head, 9));
        expectList({9, 10, 11});
        expectReturn(1);
    });
    test("insert_ordered", [=] {
        call = "insert_ordered(head, 9)";
        retval = new int(insert_ordered(head, 9));
        expectList({9});
        expectReturn(1);
    });
}
