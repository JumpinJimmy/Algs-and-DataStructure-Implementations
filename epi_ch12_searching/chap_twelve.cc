#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
#include "includes/chap_twelve.h"

SearchExercises::SearchExercises() {}

SearchExercises::~SearchExercises() {}

int SearchExercises::bsearch(int t, const std::vector<int> &A) {
    int low = 0;
    int high = A.size() - 1;
    // int result = -1;
    while (low < high) {
        int mid = low + ((high - low) / 2);
        if (A[mid] > t) {
            high = mid - 1;
        } else if (A[mid] == t) {
            return mid;
        } else {
            low = mid + 1;
        }
    }
    return -1;
}

int SearchExercises::SearchFirstOfK(const std::vector<int> &A, int k) {
    int low = 0;
    int high = A.size() - 1;
    int result = -1;
    while (low <= high) {
        int mid = low + ((high - low) / 2);
        if (A[mid] > k) {
            high = mid - 1;
        } else if (A[mid] == k) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return result;
}
