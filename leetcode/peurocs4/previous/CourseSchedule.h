#ifndef CourseSchedule_h__
#define CourseSchedule_h__


#include <unordered_map>
#include <unordered_set>
#include <deque>

using namespace std;

class Solution {
public:
  unordered_map<int, unordered_set<int>> mapHead;
  unordered_map<int, vector<int>> mapTail;

  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    for (auto prerequisite : prerequisites) {
      auto from = prerequisite[1];
      auto to = prerequisite[0];

      if (mapTail.count(from) == 0) {
        mapTail[from] = {};
      }
      mapTail[from].push_back(to);
      mapHead[to].insert(from);
    }

    deque<int> queue;
    for (int i = 0; i < numCourses; ++i) {
      if (mapHead.count(i) == 0) {
        queue.push_back(i);
      }
    }

    int count = 0;
    while (!queue.empty()) {
      auto top = queue.front();
      queue.pop_front();
      ++count;

      for (auto head : mapTail[top]) {
        mapHead[head].erase(top);
        if (mapHead[head].empty()) {
          queue.push_back(head);
        }
      }
    }

    return count == numCourses;
  }
};


#endif // CourseSchedule_h__