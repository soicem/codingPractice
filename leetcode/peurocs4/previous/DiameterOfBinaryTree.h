#pragma once
#include <algorithm>

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
  int maxDiameter = 0;

  int diameterOfBinaryTree(TreeNode* root) {
    maxDiameter = 0;
    traverse(root);
    return maxDiameter;
  }

  int traverse(TreeNode* node) {
    if (node == nullptr) { return 0; }

    int left = traverse(node->left);
    int right = traverse(node->right);

    maxDiameter = max(maxDiameter, left + right);
    return max(left, right) + 1;
  }
};