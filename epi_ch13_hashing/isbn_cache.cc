#include "includes/isbn_cache.h"
#include <iostream>

IsbnCache::IsbnCache(unsigned int capacity) : capacity_(capacity) {
    std::cout << "--->>--->> isbn_cache::constructor(capacity: " << capacity_ << ") " << std::endl;
}

IsbnCache::~IsbnCache() {
    std::cout << "--->>--->> isbn_cache::destructor " << std::endl;
}

    // if isbn already exists, do not change price
    // move to front of queue (provide table iterator for positiion)
    // if isbn does not exist
    // emplace_front on queue
    // insert into map with queue.begin
void IsbnCache::Insert(int isbn, int price) {
    auto lru_iter = lru_table_.find(isbn);

    if (lru_iter != lru_table_.end()) {
        MoveToFront(isbn, lru_iter);
    } else {
        if (lru_table_.size() == capacity_) {
            lru_table_.erase(lru_queue_.back());
            lru_queue_.pop_back();
        }
        // if at capacity, remove last item in queue
        // if (capacity)
        // emplace isbn at front and update iterator
        lru_queue_.emplace_front(isbn);
        lru_table_[isbn] = {lru_queue_.begin(), price};
    }
}

bool IsbnCache::Lookup(int isbn, int* price) {
    // if isbn exists, populate price and move to front of queue
    auto lru_iter = lru_table_.find(isbn);

    if (lru_iter != lru_table_.end()) {
        *price = lru_iter->second.second;
        MoveToFront(isbn, lru_iter);
        return true;
    }
    return false;

}

bool IsbnCache::Erase(int isbn) {
    auto lru_iter = lru_table_.find(isbn);

    if (lru_iter == lru_table_.end()) {
        return false;
    }
    lru_queue_.erase(lru_iter->second.first);
    lru_table_.erase(lru_iter);
    return true;
}

void IsbnCache::MoveToFront(int isbn, const ISBN_Table::iterator& it) {
    // erase from queue
    // put at front
    //update iterator to begining of queue
    lru_queue_.erase(it->second.first);
    lru_queue_.emplace_front(isbn);
    it->second.first = lru_queue_.begin();
    return;
}
