#pragma once
#include <cstddef>

namespace cll {
    // This is our CLL node:
    struct node {
        int data;
        node* next;
    };

    // Implement the following in src/cll/insertion.cpp:
    int append(node*& rear, int value);
    int append_unique(node*& rear, int value);
    int prepend(node*& rear, int value);
    int prepend_unique(node*& rear, int value);
    int insert_ordered(node*& rear, int value);

    // Implement the following in src/cll/removal.cpp:
    int remove(node*& rear, int value);
    int remove_all(node*& rear, int value);
    int remove_evens(node*& rear);
    int destroy(node*& rear);
}