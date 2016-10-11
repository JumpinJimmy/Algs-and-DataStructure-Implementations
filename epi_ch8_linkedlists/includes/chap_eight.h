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
    /// MergeTwoSortedLists(shared_ptr<ListNode<int>> L1, shared_ptr<ListNode<int>> L2)
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
    /// ReverseSubList(int start, int finish, shared_ptr<ListNode<int>> orig_list)
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
    /// HasCycle(const shared_ptr<ListNode<int>>& head)
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
    /// CheckOverlap(shared_ptr list_a, shared_ptr list_b)
    /// - Caller: @/* class name */
    /// - Callee: @/* class name */
    /// -------------------------------------------------------------------------------
    /// /* Description & Overview */
    /// -------------------------------------------------------------------------------
    /// - @param[in] /* parameter name */ -- /* parameter purpose */
    /// - @return[out] /* type */         -- /* description */
    /// -------------------------------------------------------------------------------
    shared_ptr<ListNode<int>> CheckOverlap(shared_ptr<ListNode<int>> list_a,
                                           shared_ptr<ListNode<int>> list_b);
    ////////////////////////////////////////////////////////////////////////////////////
    /// CreateIntLinkedList(int n) - Helper Function
    /// -------------------------------------------------------------------------------
    /// Create & Return List of linked_list_prototype structs with Integer data types
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
    /// AppendSingleNode(shared_ptr *candidate_node, shared_ptr *tail_node)
    /// -------------------------------------------------------------------------------
    /// MergeTwoSortedLists Helper Method
    /// Appends @candidate_node to @tail_node and updates @tail_node
    /// -------------------------------------------------------------------------------
    /// - @param[in] *candidate_node -- pointer to node to be assigned to @tail_node->next
    /// - @param[in] *tail_node -- current tail pointer. Update to @candidate_node after assignment
    void AppendSingleNode(shared_ptr<ListNode<int>> *candidate_node,
                          shared_ptr<ListNode<int>> *tail_node);

    ////////////////////////////////////////////////////////////////////////////////////
    /// AdvanceListNodeK(int k, shared_ptr *ListNode)
    /// -------------------------------------------------------------------------------
    /// CheckOverlap Helper Method
    /// Advances @ListNode forward @k times
    /// -------------------------------------------------------------------------------
    /// - @param[in] k -- number of times to advance @ListNode to it's next pointer
    /// - @param[in] *ListNode -- linked list node to advance
    void AdvanceListNodeK(int k, shared_ptr<ListNode<int>> *ListNode);
};

#endif // CHAP_EIGHT_H
