#ifndef CHAP_EIGHT_H
#define CHAP_EIGHT_H
#include <iostream>
#include <ios>
#include <stdlib.h>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <numeric>
#include "linked_list_prototype.h"
#include "doubly_linked_list_prototype.h"

class LinkedListExercises {
    public:
        LinkedListExercises();
        ~LinkedListExercises();
    private:
       shared_ptr<ListNode<int>> CreateLinkedList(int n);
};

#endif // CHAP_EIGHT_H
