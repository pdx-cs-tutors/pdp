#include "../include/cll_test.h"

CLLRemovalTests::CLLRemovalTests() {
    test("remove", [=] {
        call = "remove(rear, 5)";
        initialize({4, 5, 9});
        retval = new int(remove(rear, 5));
        expectList({4, 9});
        expectReturn(1);
    });
    test("remove", [=] {
        call = "remove(rear, 9)";
        initialize({4, 5, 9});
        retval = new int(remove(rear, 9));
        expectList({4, 5});
        expectReturn(1);
    });
    test("remove", [=] {
        call = "remove(rear, 4)";
        initialize({4, 5, 9});
        retval = new int(remove(rear, 4));
        expectList({5, 9});
        expectReturn(1);
    });
    test("remove", [=] {
        call = "remove(rear, 4)";
        initialize({1, 11, 2});
        retval = new int(remove(rear, 4));
        expectList({1, 11, 2});
        expectReturn(0);
    });

    test("remove_all", [=] {
        call = "remove_all(rear, 1)";
        initialize({1, 2, 1, 1, 5});
        retval = new int(remove_all(rear, 1));
        expectList({2, 5});
        expectReturn(3);
    });
    test("remove_all", [=] {
        call = "remove_all(rear, 1)";
        initialize({3, 2, 1, 1});
        retval = new int(remove_all(rear, 1));
        expectList({3, 2});
        expectReturn(2);
    });
    test("remove_all", [=] {
        call = "remove_all(rear, 1)";
        initialize({5, 6, 6});
        retval = new int(remove_all(rear, 1));
        expectList({5, 6, 6});
        expectReturn(0);
    });
    test("remove_all", [=] {
        call = "remove_all(rear, 1)";
        initialize({1});
        retval = new int(remove_all(rear, 1));
        expectList({});
        expectReturn(1);
    });

    test("remove_evens", [=] {
        call = "remove_evens(rear)";
        initialize({3, 5, 6, 7});
        retval = new int(remove_evens(rear));
        expectList({3, 5, 7});
        expectReturn(1);
    });
    test("remove_evens", [=] {
        call = "remove_evens(rear)";
        initialize({2, 3, 4, 5, 6});
        retval = new int(remove_evens(rear));
        expectList({3, 5});
        expectReturn(3);
    });
    test("remove_evens", [=] {
        call = "remove_evens(rear)";
        initialize({12, 8, 4});
        retval = new int(remove_evens(rear));
        expectList({});
        expectReturn(3);
    });
    test("remove_evens", [=] {
        call = "remove_evens(rear)";
        initialize({1, 9, 3});
        retval = new int(remove_evens(rear));
        expectList({1, 9, 3});
        expectReturn(0);
    });
    test("remove_evens", [=] {
        call = "remove_evens(rear)";
        initialize({});
        retval = new int(remove_evens(rear));
        expectList({});
        expectReturn(0);
    });

    test("destroy", [=] {
        call = "destroy(rear)";
        initialize({5, 11, 10});
        retval = new int(destroy(rear));
        expectList({});
        expectReturn(3);
    });
    test("destroy", [=] {
        call = "destroy(rear)";
        initialize({5});
        retval = new int(destroy(rear));
        expectList({});
        expectReturn(1);
    });
    test("destroy", [=] {
        call = "destroy(rear)";
        initialize({});
        retval = new int(destroy(rear));
        expectList({});
        expectReturn(0);
    });
}