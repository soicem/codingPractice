#pragma once
#include <string>
#include <unordered_map>

class Solution {
public:
  bool isAnagram(std::string s, std::string t) {
    std::unordered_map<char, int> charCounter;

    for (auto c : s) {
      ++charCounter[c];
    }

    for (auto c : t) {
      --charCounter[c];
      if (charCounter[c] == 0) {
        charCounter.erase(c);
      }
      else if (charCounter[c] < 0) { return false; }
    }

    return charCounter.empty();
  }
};
