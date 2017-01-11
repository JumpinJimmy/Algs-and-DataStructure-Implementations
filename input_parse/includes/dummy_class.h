#ifndef DUMMY_CLASS_H
#define DUMMY_CLASS_H
#include <vector>
#include <iostream>

class DummyClass {
 public:
    DummyClass();
    ~DummyClass();

    int SumList(const std::vector<int> &v = {});
    std::vector<int> FilterGreaterThan(const std::vector<int> &v, int ceil_val = 0);
    // bool IsPositive(int x);
    // bool AllPositive(const std::vector<int> &v);
    void DisplayRange(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end);

    template <typename T>
    void PrintInline(std::vector<T> list, const std::string &details = "" ) {
        if (!details.empty()) {
            std::cout << details << " ";
        }
        std::cout << " -- [ ";
        for (auto &val : list) {
            std::cout << val << " ";
        }
        std::cout << "];" << std::endl;
    };

};

#endif // DUMMY_CLASS_H