#ifndef KthLargestElementInAnArray_h__
#define KthLargestElementInAnArray_h__


#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  int findKthLargest(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    return nums[nums.size() - k];
  }
};


#endif // KthLargestElementInAnArray_h__