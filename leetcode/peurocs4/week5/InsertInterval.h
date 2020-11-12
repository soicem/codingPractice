#pragma once
#include <vector>

class Solution {
public:
  std::vector<std::vector<int>> insert(std::vector<std::vector<int>>& intervals,
                                       std::vector<int>& newInterval) {
    if (intervals.empty()) { return {newInterval}; }

    std::vector<std::vector<int>> answer;

    int newStart = newInterval[0];
    int newEnd = newInterval[1];

    int low = 0;
    int high = intervals.size() - 1;
    while (low < intervals.size() && intervals[low][1] < newStart) {
      ++low;
    }

    while (high >= 0 && newEnd < intervals[high][0]) {
      --high;
    }

    answer.insert(answer.end(), intervals.begin(), intervals.begin() + low);

    int insertStart = low < intervals.size() ? std::min(newStart, intervals[low][0]) : newStart;
    int insertEnd = high >= 0 ? std::max(newEnd, intervals[high][1]) : newEnd;
    answer.push_back({insertStart, insertEnd});

    answer.insert(answer.end(), intervals.begin() + high + 1, intervals.end());

    return answer;
  }
};
