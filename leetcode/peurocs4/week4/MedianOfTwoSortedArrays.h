#pragma once
#include <algorithm>
#include <vector>

class Solution {
public:
  double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
    nums1.insert(nums1.end(), nums2.begin(), nums2.end());
    std::sort(nums1.begin(), nums1.end());

    if (nums1.empty()) { return 0.0; }

    if (nums1.size() % 2 == 0) {
      int mid1 = nums1.size() / 2;
      int mid2 = 0.5 + nums1.size() / 2.0;
      return nums1[mid1] + (nums1[mid2] - nums1[mid1]) / 2;
    }
    else {
      int mid = nums1.size() / 2;
      return nums1[mid];
    }
  }
};
