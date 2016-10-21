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
    std::vector<int> ComputeClosestStars(std::istringstream *starmap, int k); //define a struct for representing xyz coords later

};

#endif  // CHAP_ELEVEN_H
