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
#include <exception>
#include "linked_list_prototype.h"
#include "doubly_linked_list_prototype.h"

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
/// LinkedListExercises
/// - Caller: @/* class name */
/// - Callee: @/* class name */
/// -------------------------------------------------------------------------------
/// /* Description & Overview */
/// -------------------------------------------------------------------------------
/// - @param[in] /* parameter name */ -- /* parameter purpose */
/// - @return[out] /* type */         -- /* description */
/// -------------------------------------------------------------------------------
class LinkedListExercises {
    public:
    LinkedListExercises();
    ~LinkedListExercises();

    ////////////////////////////////////////////////////////////////////////////////////
    /// MergeTwoSortedLists()
    /// - Caller: @/* class name */
    /// - Callee: @/* class name */
    /// -------------------------------------------------------------------------------
    /// /* Description & Overview */
    /// -------------------------------------------------------------------------------
    /// - @param[in] /* parameter name */ -- /* parameter purpose */
    /// - @return[out] /* type */         -- /* description */
    /// -------------------------------------------------------------------------------
    shared_ptr<ListNode<int>> MergeTwoSortedLists(shared_ptr<ListNode<int>> L1,
                                                  shared_ptr<ListNode<int>> L2);
    ////////////////////////////////////////////////////////////////////////////////////
    /// ReverseSubList()
    /// - Caller: @/* class name */
    /// - Callee: @/* class name */
    /// -------------------------------------------------------------------------------
    /// /* Description & Overview */
    /// -------------------------------------------------------------------------------
    /// - @param[in] /* parameter name */ -- /* parameter purpose */
    /// - @return[out] /* type */         -- /* description */
    /// -------------------------------------------------------------------------------
    shared_ptr<ListNode<int>> ReverseSubList(int start, int finish,
                                             shared_ptr<ListNode<int>> orig_list);
    ////////////////////////////////////////////////////////////////////////////////////
    /// HasCycle()
    /// - Caller: @/* class name */
    /// - Callee: @/* class name */
    /// -------------------------------------------------------------------------------
    /// /* Description & Overview */
    /// -------------------------------------------------------------------------------
    /// - @param[in] /* parameter name */ -- /* parameter purpose */
    /// - @return[out] /* type */         -- /* description */
    /// -------------------------------------------------------------------------------
    shared_ptr<ListNode<int>> HasCycle(const shared_ptr<ListNode<int>>& head);

    ////////////////////////////////////////////////////////////////////////////////////
    /// CreateIntLinkedList() - Helper Function
    /// -------------------------------------------------------------------------------
    /// Create and Return Integer List of linked_list_prototype structures
    /// -------------------------------------------------------------------------------
    /// - @param[in] n          -- number of linked list nodes to create
    /// - @return[out] ListNode -- shared pointer to head of new list
    /// -------------------------------------------------------------------------------
    shared_ptr<ListNode<int>> CreateIntLinkedList(int n);

    ////////////////////////////////////////////////////////////////////////////////////
    /// Print(shared_ptr<ListNode<T>> head) - Helper Function
    /// -------------------------------------------------------------------------------
    /// Print each Node within list referenced by @head on seperate lines
    /// -------------------------------------------------------------------------------
    /// - @param[in] head -- shared pointer to head of list to print
    /// -------------------------------------------------------------------------------
    template <typename T>
    void Print(shared_ptr<ListNode<T>> head) {
      if (head) {
        std::cout << "(" << head->data << ")" << std::endl;
        Print(head->next);
      }
    };

    ////////////////////////////////////////////////////////////////////////////////////
    /// PrintInline(shared_ptr<ListNode<T>> head) - Helper Function
    /// -------------------------------------------------------------------------------
    /// Print each Node within list referenced by @head in order on same line
    /// -------------------------------------------------------------------------------
    /// - @param[in] head -- shared pointer to head of list to print
    /// -------------------------------------------------------------------------------
    template <typename T>
    void PrintInline(shared_ptr<ListNode<T>> head) {
      if (head) {
        std::cout << "(" << head->data << ")";
        if (head->next) {
          std::cout << " -> ";
        } else {
            std::cout << std::endl;
        }
        PrintInline(head->next);
      }
    };

    private:
    ////////////////////////////////////////////////////////////////////////////////////
    /// MergeTwoSortedLists Helper Method
    void AppendSingleNode(shared_ptr<ListNode<int>> *candidate_node,
                          shared_ptr<ListNode<int>> *tail_node);
};

#endif // CHAP_EIGHT_H
