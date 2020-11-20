#pragma once
#include <vector>

class Solution {
public:
  int maxSubArray(std::vector<int>& nums) {
    int answer = nums[0];
    int previousMax = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
      previousMax = std::max(nums[i], nums[i] + previousMax);
      answer = std::max(answer, previousMax);
    }
    return answer;
  }
};
