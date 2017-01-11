#include "includes/dummy_class.h"
#include <iterator>
#include <algorithm>

int DummyClass::SumList(const std::vector<int> &v) {
    std::cout << "--->>--->> dummy_class:: SumList()" << std::endl;
    return std::accumulate(v.begin(), v.end(), 0);
}

std::vector<int> DummyClass::FilterGreaterThan(const std::vector<int> &v, int ceil_val) {
    std::cout << "--->>--->> dummy_class:: FilterGreaterThan()" << std::endl;
    std::vector<int> result_list;
    for (auto val : v) {
        if (val > ceil_val) {
            result_list.push_back(val);
        }
    }
    return result_list;
}

// bool DummyClass::IsPositive(int x) {
//     //http://stackoverflow.com/questions/15756331/function-pointers-generate-invalid-use-of-non-static-member-function-error
//     std::cout << "--->>--->> dummy_class:: IsPositive()" << std::endl;
//     return x > 0;
// }

// bool DummyClass::AllPositive(const std::vector<int> &v) {
//     std::cout << "--->>--->> dummy_class:: AllPositive()" << std::endl;
//     return std::all_of(v.begin(), v.end(), IsPositive);
//     return true;
// }

void DummyClass::DisplayRange(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end) {
    std::cout << "--->>--->> dummy_class:: DisplayRange()" << std::endl;
    std::cout << "{";
    std::copy(begin, end, std::ostream_iterator<int>{std::cout, ""});
    std::cout << "}";
}
