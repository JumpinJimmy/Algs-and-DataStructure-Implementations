#ifndef CHAP_THIRTEEN_H
#define CHAP_THIRTEEN_H
#include <string>
#include <vector>

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
/// HashTableExercises
/// - Caller: @/* class name */
/// - Callee: @/* class name */
/// -------------------------------------------------------------------------------
/// /* Description & Overview */
/// -------------------------------------------------------------------------------
/// - @param[in] /* parameter name */ -- /* parameter purpose */
/// - @return[out] /* type */         -- /* description */
/// -------------------------------------------------------------------------------
class HashTableExercises {
 public:
    HashTableExercises();
    ~HashTableExercises();
    bool PermuteToPalindrome(const std::string &subject_string);
    bool ConstructibleLetter(const std::string &subject_letter, const std::string &magazine_text);
    int ShortestEqualValueDistance(const std::vector<std::string> &str_list);
    std::pair<int,int> RetreiveContainingSubarraryIndex(const std::vector<std::string> &content_array, const std::set<std::string> &search_keys);

};

#endif  // CHAP_THIRTEEN_H
