#pragma once
#include <vector>

class Solution {
public:
  double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
    if (nums1.empty() && nums2.empty()) { return 0.0; }
    if (nums1.empty()) {
      auto mid1 = nums2.size() / 2.0 - 0.5;
      auto mid2 = nums2.size() / 2.0;
      return nums2[mid1] + (nums2[mid2] - nums2[mid1]) / 2.0;
    }
    if (nums2.empty()) {
      auto mid1 = nums1.size() / 2.0 - 0.5;
      auto mid2 = nums1.size() / 2.0;
      return nums1[mid1] + (nums1[mid2] - nums1[mid1]) / 2.0;
    }

    auto totalSize = nums1.size() + nums2.size();
    auto count = 0;
    auto i1 = 0;
    auto i2 = 0;
    auto val1 = 0;
    auto val2 = 0;
    while (count <= totalSize / 2) {
      val1 = val2;
      if (i1 < nums1.size() && (i2 >= nums2.size() || nums1[i1] < nums2[i2])) {
        val2 = nums1[i1];
        ++i1;
      }
      else {
        val2 = nums2[i2];
        ++i2;
      }
      ++count;
    }
    return totalSize % 2 ? val2 : val1 + (val2 - val1) / 2.0;
  }
};
