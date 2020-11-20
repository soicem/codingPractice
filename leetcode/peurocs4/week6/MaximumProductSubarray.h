#pragma once
#include <vector>

class Solution {
public:
  int maxProduct(std::vector<int>& nums) {
    if (nums.empty()) { return 0; }

    int answer = nums[0];
    int prevMax = 1;
    int prevMin = 1;
    for (auto num : nums) {
      int temp[2] {
        prevMax * num,
        prevMin * num
      };
      prevMax = std::max(temp[0], temp[1]);
      prevMax = std::max(prevMax, num);
      prevMin = std::min(temp[0], temp[1]);
      prevMin = std::min(prevMin, num);

      answer = std::max(answer, prevMax);
    }
    return answer;
  }
};
