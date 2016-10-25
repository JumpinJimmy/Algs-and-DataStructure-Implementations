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

/// TODO(jdevore):  this will not be efficient for arrays that contain duplicates. Must work on linear solution
int SearchExercises::SearchSmallest(const std::vector<int> &A) {
    int low = 0;
    int high = A.size() - 1;
    while (low < high) {
        int mid = low + ((high - low) / 2);
        if (A[mid] > A[high]) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    return high;
}

int SearchExercises::IntegerSquareRoot(int k) {
    int low = 0;
    int high = k;
    while (low <= high) {
        long mid = low + ((high - low) / 2);
        long mid_square = mid * mid;
        if (mid_square <= k) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return low - 1;
}

int SearchExercises::FindKthLargest(int k, std::vector<int> *list_ptr) {
    return FindKth(k, std::greater<int>(), list_ptr);
}
