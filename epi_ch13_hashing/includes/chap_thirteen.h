#ifndef CHAP_THIRTEEN_H
#define CHAP_THIRTEEN_H
#include <string>
#include <vector>
#include <unordered_set>

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
    std::pair<int,int> RetreiveCoveringSubarraryIndex(const std::vector<std::string> &content_arr,
                                                        const std::unordered_set<std::string> &search_keys);
    //// Book Solution is FindSmallestSubarrayCoveringSet
    ///TODO(jdevore): implement and understand Books solution for Subarray problem
    // std::pair<int,int> FindSmallestSubarrayCoveringSet(
    //     const vector<string> &paragraph, const unordered_set<string> &keywords);

    // Helper Functions
    template <typename T>
    void PrintCollection(const std::vector<T> &v) {
        std::cout << "PrintCollection: \n [ ";
        for (auto &val : v) {
            std::cout << val << " ";
        }
        std::cout << "];" << std::endl;
    }

    template <typename T>
    void PrintSet(const std::unordered_set<T> &s) {
        std::cout << "PrintSet: \n [ ";
        for (auto &val : s) {
            std::cout << val << " ";
        }
        std::cout << "];" << std::endl;
    }
//     for (const auto& elem: mySet) {
//     /* ... process elem ... */
// }

};

#endif  // CHAP_THIRTEEN_H
