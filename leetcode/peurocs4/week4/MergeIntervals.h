#pragma once
#include <algorithm>
#include <vector>

class Solution {
public:
  std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
    if (intervals.empty()) { return {}; }

    std::vector<std::vector<int>> answer;
    std::sort(intervals.begin(), intervals.end());

    auto begin = intervals[0][0];
    auto end = intervals[0][1];
    for (int i = 1; i < intervals.size(); ++i) {
      auto& interval = intervals[i];
      auto iBegin = interval[0];
      auto iEnd = interval[1];

      if (end >= iBegin) {
        end = std::max(end, iEnd);
      }
      else {
        answer.push_back({begin, end});
        begin = iBegin;
        end = iEnd;
      }
    }
    answer.push_back({begin, end});
    return answer;
  }
};
