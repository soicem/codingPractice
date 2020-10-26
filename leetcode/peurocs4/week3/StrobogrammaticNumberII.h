#pragma once

#include <sstream>
#include <unordered_map>

class Solution {
public:
  std::unordered_map<int, int> flippable = {
    {0, 0},
    {1, 1}, 
    {6, 9},
    {8, 8},
    {9, 6}
  };

  std::vector<std::string> findStrobogrammatic(int n) {
    if (n == 0) { return {""}; }
    if (n == 1) { return {"0", "1", "8"}; }
    
    std::vector<std::string> answer;

    std::vector<int> stk;
    int left = (n + 1) / 2;
    bool isOdd = n % 2;
    recurse(stk, left, isOdd, answer);
    
    return answer;
  }
  
  void recurse(std::vector<int>& stk, int left, bool isOdd, std::vector<std::string>& answer) {
    if (left == 0) {
      if (isOdd && stk.back() != flippable[stk.back()]) { return; }

      std::stringstream ss;
      for (int i = 0; i < stk.size(); ++i) {
        auto val = stk[i];
        ss << val;
      }
      int reverseFrom = isOdd ? stk.size() - 2 : stk.size() - 1;
      for (int i = reverseFrom; i >= 0; --i) {
        auto val = stk[i];
        ss << flippable[val];
      }
      
      answer.push_back(ss.str());
      return;
    }
    
    for (auto kv : flippable) {
      auto k = kv.first;
      auto v = kv.second;
      
      if (stk.empty() && k == 0) { continue; }
      
      stk.push_back(k);
      recurse(stk, left - 1, isOdd, answer);
      stk.pop_back();
    }
  }
};