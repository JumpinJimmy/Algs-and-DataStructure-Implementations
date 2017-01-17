#ifndef ISBN_CACHE_H
#define ISBN_CACHE_H
#include <unordered_map>
#include <list>
typedef std::unordered_map<int, std::pair<std::list<int>::iterator, int>> ISBN_Table;
class IsbnCache {
 public:
    IsbnCache(unsigned int capacity = 2);
    ~IsbnCache();
    void Insert(int isbn, int price);
    bool Lookup(int isbn, int* price);
    bool Erase(int isbn);

 private:


    void MoveToFront(int isbn, const ISBN_Table::iterator& it);
    unsigned int capacity_;

    std::list<int> lru_queue_;
    ISBN_Table lru_table_;
};

#endif // ISBN_CACHE_H
