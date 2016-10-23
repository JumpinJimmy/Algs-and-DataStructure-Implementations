#ifndef CHAP_TWELVE_H
#define CHAP_TWELVE_H
#include <vector>

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
/// SearchExercises
/// - Caller: @/* class name */
/// - Callee: @/* class name */
/// -------------------------------------------------------------------------------
/// /* Description & Overview */
/// -------------------------------------------------------------------------------
/// - @param[in] /* parameter name */ -- /* parameter purpose */
/// - @return[out] /* type */         -- /* description */
/// -------------------------------------------------------------------------------
class SearchExercises {
 public:
    SearchExercises();
    ~SearchExercises();

    ////////////////////////////////////////////////////////////////////////////////////
    /// SearchFirstOfK(shared_ptr<ListNode<int>> L1, shared_ptr<ListNode<int>> L2)
    /// - Caller: @/* class name */
    /// - Callee: @/* class name */
    /// -------------------------------------------------------------------------------
    /// /* Description & Overview */
    /// -------------------------------------------------------------------------------
    /// - @param[in] /* parameter name */ -- /* parameter purpose */
    /// - @return[out] /* type */         -- /* description */
    /// -------------------------------------------------------------------------------
    int SearchFirstOfK(const std::vector<int> &A, int k);
};

#endif  // CHAP_TWELVE_H
