#include <cassert> //NOLINT
#include <iostream>
#include <memory>
#include <algorithm>
#include <sstream>
#include <iterator>
#include <limits>
#include <random>
#include "includes/chap_thirteen.h"
#include "includes/isbn_cache.h"

// Test Exercise 13.1
void PermuteToPalindrome(HashTableExercises* ht_exerciser) {
    std::vector<std::string> source_str_list {"Hello James", "raeccar", "acbba",
                                              "Hockenheim", "James", "staythesame", "AEIOUaeiou"};
    for (auto &test_str : source_str_list) {
        std::cout << "--->>--->> HashTables:: PermuteToPalindrome(\"" << test_str << "\"): "
                  << std::boolalpha << ht_exerciser->PermuteToPalindrome(test_str) << std::endl;
    }
}

// Test Exercise 13.2
void IsLetterConstructible(HashTableExercises* ht_exerciser) {
    std::vector<std::string> letter_list {"123", "123", "GATTACA", "a", "aa", "staythesame", ""};
    std::vector<std::string> magazine_list {"456", "12222222", "A AD FS GA T ACA TTT", "", "aa", "staythesame", "123"};
    std::vector<std::pair<std::string, std::string>> letter_mag_list;
    letter_mag_list.reserve(magazine_list.size());
    std::transform(letter_list.begin(), letter_list.end(), magazine_list.begin(),
                   std::back_inserter(letter_mag_list), [](std::string a, std::string b) {
                    return std::make_pair(a, b); });

    for (auto &test_iter : letter_mag_list) {
        std::cout << "--->>--->> HashTables:: ConstructibleLetter(letter: \"" << test_iter.first << "\", mag: \"" << test_iter.second << "\"): "
                  << std::boolalpha << ht_exerciser->ConstructibleLetter(test_iter.first, test_iter.second) << std::endl;
    }
    assert(!ht_exerciser->ConstructibleLetter("Bastian Schweinsteiger", "Thomas Muller"));
    assert(ht_exerciser->ConstructibleLetter("JumpinJimmy", "JumpinJimmy Is His Name"));
}

// Test Exercise 13.3
void TestLruCache() {
    std::cout << "--->>--->> HashTables:: TestLruCache() " << std::endl;
    std::unique_ptr<IsbnCache> isbn_cache(new IsbnCache(2));
    std::cout << "--->>--->> HashTables:: TestLruCache -> Test Capacity Constraint " << std::endl;
    std::cout << "         |___ HasTables:: TestLruCache.  isbn_cache->Insert(1, 1);" << std::endl;
    isbn_cache->Insert(1, 1);
    std::cout << "         |___ HasTables:: TestLruCache.  isbn_cache->Insert(2, 1);" << std::endl;
    isbn_cache->Insert(2, 1);
    std::cout << "         |___ HasTables:: TestLruCache.  isbn_cache->Insert(3, 1);" << std::endl;
    isbn_cache->Insert(3, 1);
    std::cout << "         |___ HasTables:: TestLruCache.  isbn_cache->Insert(4, 1);" << std::endl;
    isbn_cache->Insert(4, 1);
    int val = 0;
    assert(!isbn_cache->Lookup(1, &val));
    assert(!isbn_cache->Lookup(2, &val));
    assert(isbn_cache->Lookup(3, &val));
    assert(val == 1);
    assert(isbn_cache->Lookup(4, &val));
    assert(val == 1);
    isbn_cache.reset(new IsbnCache(2));

    std::cout << "--->>--->> HashTables:: TestLruCache-> Test Update Moves Front " << std::endl;
    isbn_cache->Insert(1, 1);
    isbn_cache->Insert(2, 1);
    isbn_cache->Insert(3, 1);
    isbn_cache->Insert(2, 2);
    isbn_cache->Insert(4, 1);
    assert(!isbn_cache->Lookup(1, &val));
    assert(isbn_cache->Lookup(2, &val));
    assert(val == 1);
    assert(!isbn_cache->Lookup(3, &val));
    assert(isbn_cache->Lookup(4, &val));
    assert(val == 1);
    isbn_cache.reset(new IsbnCache(2));

    std::cout << "--->>--->> HashTables:: TestLruCache -> Test Remove " << std::endl;
    isbn_cache->Insert(1, 1);
    isbn_cache->Insert(2, 1);
    isbn_cache->Erase(2);
    isbn_cache->Insert(3, 3);
    assert(isbn_cache->Lookup(1, &val));
    assert(val == 1);
    assert(!isbn_cache->Lookup(2, &val));
    assert(isbn_cache->Lookup(3, &val));
    assert(val == 3);
}

// Helper for Test Exercise 13.6
std::string RandString(int len) {
  std::default_random_engine gen((std::random_device())());
  std::string ret = "";
  while (len--) {
    std::uniform_int_distribution<int> dis('a', 'z');
    ret += dis(gen);
  }
  return ret;
}

// Helper for Test Exercise 13.6
int ShortestDistanceCheckAnswer(const std::vector<std::string>& s) {
  int nearest_repeated_distance = std::numeric_limits<int>::max();
  for (int i = 0; i < s.size(); ++i) {
    for (int j = i + 1; j < s.size(); ++j) {
      if (s[i] == s[j]) {
        nearest_repeated_distance = std::min(nearest_repeated_distance, j - i);
      }
    }
  }
  return (nearest_repeated_distance < std::numeric_limits<int>::max()) ? nearest_repeated_distance : -1;
}

// Test Exercise 13.6
void ShortestDistanceBetweenEquals(HashTableExercises* ht_exerciser, int test_iterations = 0) {
    std::cout << "--->>--->> HashTables::ShortestDistanceBetweenEquals()" << std::endl;
    std::vector<std::string> A = {"foo", "bar", "widget", "foo", "xyz", "widget", "bar", "adnan"};
    assert(ShortestDistanceCheckAnswer(A) == ht_exerciser->ShortestEqualValueDistance(A));
    A = {"foo", "foo", "widget", "foo", "xyz", "widget", "bar", "adnan"};
    assert(ShortestDistanceCheckAnswer(A) == ht_exerciser->ShortestEqualValueDistance(A));
    std::cout << "--->>--->> main:: random test "  << std::endl;
    std::default_random_engine gen((std::random_device())());
    for (int times = 0; times < 1000; ++times) {
        int n;
        if (test_iterations == 0) {
            std::uniform_int_distribution<int> dis(1, 10000);
            n = dis(gen);
        } else {
            n = test_iterations;
        }
        std::vector<std::string> s;
        for (int i = 0; i < n; ++i) {
            std::uniform_int_distribution<int> dis(1, 10);
            s.emplace_back(RandString(dis(gen)));
        }
        assert(ShortestDistanceCheckAnswer(s) == ht_exerciser->ShortestEqualValueDistance(s));
    }
}

void RetreiveCoveringSubarraryIndex(HashTableExercises* ht_exerciser) {
    std::vector<std::string> v = {"Hello", "my", "name", "is", "x", "and", "my", "favorite", "thing", "x"};
    std::unordered_set<std::string> search_keys = {"my", "x"};
    std::vector<std::string> A = {"a", "b", "c", "b", "a", "d", "c", "a", "e", "a", "a", "b", "e"};
    std::unordered_set<std::string> dict = {"b", "c", "e"};
    int expected_start = 3;
    int expected_finish = 8;
    ht_exerciser->RetreiveCoveringSubarraryIndex(v, search_keys);
    auto result = ht_exerciser->RetreiveCoveringSubarraryIndex(A, dict);
    std::cout << "res = " << result.first << " " << result.second << std::endl;
    assert(result.first == expected_start && result.second == expected_finish);
    dict = {"a", "c"};
    expected_start = 6;
    expected_finish = 7;
    result = ht_exerciser->RetreiveCoveringSubarraryIndex(A, dict);
    std::cout << "res = " << result.first << " " << result.second << std::endl;
    assert(result.first == expected_start && result.second == expected_finish);
    A = {"a", "b"};
    dict = {"a", "b"};
    expected_start = 0;
    expected_finish = 1;
    result = ht_exerciser->RetreiveCoveringSubarraryIndex(A, dict);
    std::cout << "res = " << result.first << " " << result.second << std::endl;
    assert(result.first == expected_start && result.second == expected_finish);
    A = {"a", "b"};
    dict = {"b", "a"};
    expected_start = 0;
    expected_finish = 1;
    result = ht_exerciser->RetreiveCoveringSubarraryIndex(A, dict);
    std::cout << "res = " << result.first << " " << result.second << std::endl;
    assert(result.first == expected_start && result.second == expected_finish);
}

void AltMinCoveringSubarry(HashTableExercises* ht_exerciser) {
    std::vector<std::string> v = {"Hello", "my", "name", "is", "x", "and", "my", "favorite", "thing", "x"};
    std::unordered_set<std::string> search_keys = {"my", "x"};
    std::vector<std::string> A = {"a", "b", "c", "b", "a", "d", "c", "a", "e", "a", "a", "b", "e"};
    std::unordered_set<std::string> dict = {"b", "c", "e"};
    int expected_start = 3;
    int expected_finish = 8;
    ht_exerciser->AltMinCoveringSubarry(v, search_keys);
    auto result = ht_exerciser->AltMinCoveringSubarry(A, dict);
    std::cout << "res = " << result.first << " " << result.second << std::endl;
    assert(result.first == expected_start && result.second == expected_finish);
}

void RunTests(std::shared_ptr<HashTableExercises> ht_exerciser) {
    std::cout << "--->>--->> HashTables::RunTests <<---<<--- " << std::endl;
    // PermuteToPalindrome(ht_exerciser.get());
    // IsLetterConstructible(ht_exerciser.get());
    // TestLruCache();
    // ShortestDistanceBetweenEquals(ht_exerciser.get(), 4);
    // RetreiveCoveringSubarraryIndex(ht_exerciser.get());
    AltMinCoveringSubarry(ht_exerciser.get());
}

// valgrind --leak-check=full --show-leak-kinds=all ./ch13_test
int main(int argc, char const *argv[]) {
    std::shared_ptr<HashTableExercises> ht_exerciser(new HashTableExercises());
    RunTests(ht_exerciser);
    return 0;
}
