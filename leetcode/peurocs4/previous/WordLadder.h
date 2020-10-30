#pragma once

#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
  unordered_map<string, vector<string>> wildcards;

  int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    for (auto word : wordList) {
      for (int i = 0; i < word.size(); ++i) {
        auto wordWildcard = word;
        wordWildcard[i] = '*';

        if (wildcards.count(wordWildcard) == 0) {
          wildcards[wordWildcard] = {};
        }
        wildcards[wordWildcard].push_back(word);
      }
    }

    unordered_set<string> used {beginWord};
    vector<string> queue {beginWord};
    int left = 0;
    int right = queue.size();
    int length = 1;
    while (left < right) {
      for (; left < right; ++left) {
        auto word = queue[left];

        for (int i = 0; i < word.size(); ++i) {
          auto wordWildcard = word;
          wordWildcard[i] = '*';

          for (auto candidate : wildcards[wordWildcard]) {
            if (candidate == endWord) { return length + 1; }
            if (used.count(candidate) > 0) { continue; }

            queue.push_back(candidate);
            used.insert(candidate);
          }
        }
      }
      ++length;
      right = queue.size();
    }

    return 0;
  }
};