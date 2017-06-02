#include "../include/cll_test.h"

CLLInsertionTests::CLLInsertionTests() {
    test("append", [=] {
        call = "append(rear, 1)";
        initialize({3, 2});
        retval = new int(append(rear, 1));
        expectList({3, 2, 1});
        expectReturn(1);
    });
    test("append", [=] {
        call = "append(rear, 1)";
        retval = new int(append(rear, 1));
        expectList({1});
        expectReturn(1);
    });

    test("append_unique", [=] {
        call = "append_unique(rear, 2)";
        initialize({3, 2, 1});
        retval = new int(append_unique(rear, 2));
        expectList({3, 2, 1});
        expectReturn(0);
    });
    test("append_unique", [=] {
        call = "append_unique(rear, 2)";
        initialize({3, 1, 9});
        retval = new int(append_unique(rear, 2));
        expectList({3, 1, 9, 2});
        expectReturn(1);
    });
    test("append_unique", [=] {
        call = "append_unique(rear, 2)";
        retval = new int(append_unique(rear, 2));
        expectList({2});
        expectReturn(1);
    });

    test("prepend", [=] {
        call = "prepend(rear, 5)";
        retval = new int(prepend(rear, 5));
        expectList({5});
        expectReturn(1);
    });
    test("prepend", [=] {
        call = "prepend(rear, 5)";
        initialize({0, 3});
        retval = new int(prepend(rear, 5));
        expectList({5, 0, 3});
        expectReturn(1);
    });

    test("prepend_unique", [=] {
        call = "prepend_unique(rear, 7)";
        initialize({6, 1});
        retval = new int(prepend_unique(rear, 7));
        expectList({7, 6, 1});
        expectReturn(1);
    });
    test("prepend_unique", [=] {
        call = "prepend_unique(rear, 7)";
        initialize({8, 7, 5});
        retval = new int(prepend_unique(rear, 7));
        expectList({8, 7, 5});
        expectReturn(0);
    });
    test("prepend_unique", [=] {
        call = "prepend_unique(rear, 7)";
        retval = new int(prepend_unique(rear, 7));
        expectList({7});
        expectReturn(1);
    });

    test("insert_ordered", [=] {
        call = "insert_ordered(rear, 3)";
        initialize({1, 4, 5});
        retval = new int(insert_ordered(rear, 3));
        expectList({1, 3, 4, 5});
        expectReturn(1);
    });
    test("insert_ordered", [=] {
        call = "insert_ordered(rear, 1)";
        initialize({3, 4, 5});
        retval = new int(insert_ordered(rear, 1));
        expectList({1, 3, 4, 5});
        expectReturn(1);
    });
    test("insert_ordered", [=] {
        call = "insert_ordered(rear, 5)";
        initialize({1, 3, 4});
        retval = new int(insert_ordered(rear, 5));
        expectList({1, 3, 4, 5});
        expectReturn(1);
    });
    test("insert_ordered", [=] {
        call = "insert_ordered(rear, 1)";
        retval = new int(insert_ordered(rear, 1));
        expectList({1});
        expectReturn(1);
    });
}
