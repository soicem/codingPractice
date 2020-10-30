#pragma once

#include <vector>
#include <unordered_set>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
  stringstream answer;
  unordered_set<string> used;

  string crackSafe(int n, int k) {
    if (n == 1 && k == 1) { return "0"; }

    stringstream ss;
    for (int i = 0; i < n - 1; ++i) {
      ss << '0';
    }
    string start = ss.str();

    dfs(start, k);
    answer << start;
    return answer.str();
  }

  void dfs(string start, int k) {
    for (int i = 0; i < k; ++i) {
      string newString(start);
      newString.push_back(i + '0');

      if (used.count(newString) == 0) {
        used.insert(newString);
        dfs(newString.substr(1), k);
        answer << i;
      }
    }
  }
};
