#include <iostream>
#include <bitset>
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

/// TODO(jdevore):  this will not be efficient for arrays that contain duplicates.
/// Must work on linear solution
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
        int64_t mid = low + ((high - low) / 2);
        int64_t mid_square = mid * mid;
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

/// find missing value of 8bit values within file
int SearchExercises::FindMissingElement8(std::ifstream* ifs) {
    const int kNumBuckets = 1 << 4;
    std::cout << "======= FindMissingElement8 kNumBuckets: " << kNumBuckets << std::endl;
    std::vector<size_t> counter(kNumBuckets, 0);
    PrintListInline(counter, "FindMissingElement8");
    unsigned int x;
    while (*ifs >> x) {
        int upper_portion_x = x >> 4;
        ++counter[upper_portion_x];
    }
    PrintListInline(counter, "FindMissingElement8");

    const int kBucketCapacity = 1 << 4;
    std::cout << "======= FindMissingElement8 kBucketCapacity: " << kBucketCapacity << std::endl;
    int candidate_bucket = -1;
    for (int i = 0; i < kNumBuckets; ++i) {
        if (counter[i] < kBucketCapacity) {
            candidate_bucket = i;
            std::cout << "======= FindMissingElement8 candidate_bucket " << candidate_bucket << std::endl;
            break;
        }
    }

    if (candidate_bucket < 0) {
        std::cout << "======= FindMissingElement8:: No Missing element " << std::endl;
        return 0;
    }

    ifs->clear();
    ifs->seekg(0, std::ios::beg);
    std::bitset<kBucketCapacity> bit_vec(0);
    while (*ifs >> x) {
        int upper_part_x = x >> 4;
        if (candidate_bucket == upper_part_x) {
            std::cout << "FindMissingElement8::candidate_bucket(" << candidate_bucket << ") == upper_part_x(" << upper_part_x << ")" << std::endl;
            int lower_part_x = ((1 << 4) - 1) & x;
            std::cout << "FindMissingElement8::lower_part_x:" << lower_part_x << std::endl;
            bit_vec.set(lower_part_x);
        }
    }
    ifs->close();

    // At least one of the LSB combinations is absent, find it.
    for (int i = 0; i < kBucketCapacity; ++i) {
        if (bit_vec[i] == 0) {
            std::cout << "======= FindMissingElement8:: bit_vec[" << i << "] == 0 " << std::endl;
            return (candidate_bucket << 4) | i;
        }
    }

    std::cout << "======= FindMissingElement8:: No Missing element " << std::endl;
    return 0;
}
