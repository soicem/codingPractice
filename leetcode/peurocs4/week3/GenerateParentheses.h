#pragma once
#include <string>
#include <vector>

class Solution {
public:
  std::vector<std::string> answer;

  std::vector<std::string> generateParenthesis(int n) {
    std::string str;
    recurse(n, n, str);
    return answer;
  }

  void recurse(int openLeft, int closeLeft, std::string& str) {
    if (openLeft == 0 && closeLeft == 0) {
      answer.emplace_back(str);
    }

    if (openLeft > 0) {
      str.push_back('(');
      recurse(openLeft - 1, closeLeft, str);
      str.pop_back();
    }

    if (closeLeft > 0 && closeLeft > openLeft) {
      str.push_back(')');
      recurse(openLeft, closeLeft - 1, str);
      str.pop_back();
    }
  }
};
