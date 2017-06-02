#include "../include/lll_test.h"

LLLRemovalTests::LLLRemovalTests() {
    test("remove", [=] {
        call = "remove(head, 8)";
        initialize({3, 8, 1, 4});
        retval = new int(remove(head, 8));
        expectList({3, 1, 4});
        expectReturn(1);
    });
    test("remove", [=] {
        call = "remove(head, 6)";
        initialize({9, 9, 4});
        retval = new int(remove(head, 6));
        expectList({9, 9, 4});
        expectReturn(0);
    });
    test("remove", [=] {
        call = "remove(head, 6)";
        initialize({1, 2, 6});
        retval = new int(remove(head, 6));
        expectList({1, 2});
        expectReturn(1);
    });
    test("remove", [=] {
        call = "remove(head, 6)";
        initialize({6, 1, 2, 6});
        retval = new int(remove(head, 6));
        expectList({1, 2, 6});
        expectReturn(1);
    });
    test("remove", [=] {
        call = "remove(head, 4)";
        retval = new int(remove(head, 4));
        expectList({});
        expectReturn(0);
    });

    test("remove_all", [=] {
        call = "remove_all(head, 8)";
        initialize({3, 8, 1, 4});
        retval = new int(remove_all(head, 8));
        expectList({3, 1, 4});
        expectReturn(1);
    });
    test("remove_all", [=] {
        call = "remove_all(head, 9)";
        initialize({9, 9, 4});
        retval = new int(remove_all(head, 9));
        expectList({4});
        expectReturn(2);
    });
    test("remove_all", [=] {
        call = "remove_all(head, 6)";
        initialize({1, 2, 6, 6});
        retval = new int(remove_all(head, 6));
        expectList({1, 2});
        expectReturn(2);
    });
    test("remove_all", [=] {
        call = "remove_all(head, 6)";
        initialize({6, 1, 2, 6});
        retval = new int(remove_all(head, 6));
        expectList({1, 2});
        expectReturn(2);
    });
    test("remove_all", [=] {
        call = "remove_all(head, 4)";
        retval = new int(remove_all(head, 4));
        expectList({});
        expectReturn(0);
    });

    test("remove_evens", [=] {
        call = "remove_evens(head)";
        retval = new int(remove_evens(head));
        expectList({});
        expectReturn(0);
    });
    test("remove_evens", [=] {
        call = "remove_evens(head)";
        initialize({2, 4, 6, 8});
        retval = new int(remove_evens(head));
        expectList({});
        expectReturn(4);
    });
    test("remove_evens", [=] {
        call = "remove_evens(head)";
        initialize({2, 3, 6, 7});
        retval = new int(remove_evens(head));
        expectList({3, 7});
        expectReturn(2);
    });
    test("remove_evens", [=] {
        call = "remove_evens(head)";
        initialize({1, 3, 5, 7});
        retval = new int(remove_evens(head));
        expectList({1, 3, 5, 7});
        expectReturn(0);
    });
}
