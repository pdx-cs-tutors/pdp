#pragma once
#include <cstddef>

namespace lll {
    // This is our LLL node:
    struct node {
        int data;
        node* next;
    };

    // Implement the following in src/lll/insertion.cpp:
    int append(node*& head, int value);
    int append_unique(node*& head, int value);
    int prepend(node*& head, int value);
    int prepend_unique(node*& head, int value);
    int insert_ordered(node*& head, int value);

    // Implement the following in src/lll/removal.cpp:
    int remove(node*& head, int value);
    int remove_all(node*& head, int value);
    int remove_evens(node*& head);
    int destroy(node*& head);
}
