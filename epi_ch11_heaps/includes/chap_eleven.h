#ifndef CHAP_ELEVEN_H
#define CHAP_ELEVEN_H
#include <vector>
#include <sstream>
#include <memory>
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
/// HeapExercises
/// - Caller: @/* class name */
/// - Callee: @/* class name */
/// -------------------------------------------------------------------------------
/// /* Description & Overview */
/// -------------------------------------------------------------------------------
/// - @param[in] /* parameter name */ -- /* parameter purpose */
/// - @return[out] /* type */         -- /* description */
/// -------------------------------------------------------------------------------
class HeapExercises {
 public:
    HeapExercises();
    ~HeapExercises();
    std::vector<int> SortKSortedList(std::istringstream *sequence, int k);


};

#endif  // CHAP_ELEVEN_H
