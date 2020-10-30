#pragma once

#include <algorithm>
#include <climits>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
  int maxSum = INT_MIN;

  int maxPathSum(TreeNode* root) {
    maxSum = INT_MIN;
    traverse(root);
    return maxSum;
  }

  int traverse(TreeNode* node) {
    if (node == nullptr) { return 0; }

    const int left = max(0, traverse(node->left));
    const int right = max(0, traverse(node->right));
    const int sum = node->val + left + right;
    maxSum = max(maxSum, sum);

    return node->val + max(left, right);
  }
};