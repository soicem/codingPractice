#pragma once
#include <string>

class Solution {
public:
  std::string longestPalindrome(std::string s) {
    if (s.size() < 2) { return s; }

    int maxLength = 0;
    int maxAt = 0;
    for (int i = 0; i < s.size() - 1; ++i) {
      auto length = recurse(s, i, i);
      length = std::max(length, recurse(s, i, i + 1));

      if (length > maxLength) {
        maxLength = length;
        maxAt = i - (maxLength - 1) / 2;
      }
    }
    return s.substr(maxAt, maxLength);
  }

  int recurse(std::string& s, int low, int high) {
    if (low < 0 || high >= s.size()) { return 0; }
    if (s[low] != s[high]) { return 0; }

    auto length = recurse(s, low - 1, high + 1);
    return (length == 0) ? (high - low + 1) : (length);
  }
};
