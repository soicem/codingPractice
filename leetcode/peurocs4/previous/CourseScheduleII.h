#pragma once

#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <deque>

using namespace std;

#define MAX_COURSES (2001)

class Solution {
public:
  unordered_map<int, unordered_set<int>> mappingTo;
  unordered_map<int, unordered_set<int>> mappingFrom;

  vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    for (auto& prerequisite : prerequisites) {
      auto to = prerequisite[0];
      auto from = prerequisite[1];

      mappingFrom[to].insert(from);
      mappingTo[from].insert(to);
    }

    deque<int> queue;
    for (int i = 0; i < numCourses; ++i) {
      if (mappingFrom.count(i) == 0) {
        queue.push_back(i);
      }
    }

    vector<int> answer;
    while (!queue.empty()) {
      auto candidate = queue.front();
      queue.pop_front();

      answer.push_back(candidate);

      for (auto& to : mappingTo[candidate]) {
        mappingFrom[to].erase(candidate);
        if (mappingFrom[to].empty()) {
          queue.push_back(to);
        }
      }
    }
    
    if (answer.size() != numCourses) { return {}; }

    return answer;
  }
};