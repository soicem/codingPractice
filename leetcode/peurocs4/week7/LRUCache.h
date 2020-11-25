#pragma once
#include <queue>
#include <unordered_map>

class LRUCache {
private:
  std::unordered_map<int, std::pair<int, int>> cache; //fist: value, second: usedCount
  std::queue<int> usedQueue;
  int capacity = 0;

public:
  LRUCache(int capacity): capacity(capacity) {
  }

  int get(int key) {
    if (!hasKey(key)) {
      return -1;
    }
    markedUsed(key);
    return cache[key].first;
  }

  void put(int key, int value) {
    if (hasKey(key)) {
      cache[key].first = value;
      markedUsed(key);
    }
    else {
      if (isFull()) {
        removeLeastUsed();
      }
      cache[key] = {value, 0};
      markedUsed(key);
    }
  }

  bool isFull() {
    return cache.size() == capacity;
  }

  bool hasKey(int key) {
    return cache.count(key) > 0;
  }

private:
  void markedUsed(int key) {
    ++cache[key].second;
    usedQueue.push(key);
  }

  void removeLeastUsed() {
    int key = 0;
    do {
      key = usedQueue.front();
      --cache[key].second;
      usedQueue.pop();
    } while (cache[key].second > 0);
    cache.erase(key);
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
