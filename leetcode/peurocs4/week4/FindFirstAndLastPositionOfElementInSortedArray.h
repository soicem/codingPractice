#pragma once
#include <vector>

class Solution {
public:
  std::vector<int> searchRange(std::vector<int>& nums, int target) {
    std::vector<int> answer = {-1, -1};

    if (nums.empty()) { return answer; }

    auto left = 0;
    auto right = nums.size() - 1;
    while (left < right) {
      auto middle = left + (right - left) / 2;

      if (nums[middle] < target) {
        left = middle + 1;
      }
      else {
        right = middle - 1;
      }
    }

    if (left < 0 || nums[left] != target) { return answer; }
    answer[0] = left;

    left = 0;
    right = nums.size() - 1;
    while (left < right) {
      auto middle = left + (right - left + 1) / 2;

      if (nums[middle] <= target) {
        left = middle + 1;
      }
      else {
        right = middle - 1;
      }
    }

    answer[1] = right;
    return answer;
  }
};
