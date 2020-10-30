#ifndef CountCompleteTreeNodes_h__
#define CountCompleteTreeNodes_h__


#include <vector>

using namespace std;

#define ull unsigned long long

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class BitStack {
public:
  ull stackValue = 0;

  void push(bool bit) {
    stackValue <<= 1;
    if (bit) {
      stackValue |= 1;
    }
  }

  bool pop() {
    const bool value = stackValue & 1;
    stackValue >>= 1;
    return value;
  }
};

class Solution {
public:
  BitStack* bitStack;
  int maxDepth;
  uint32_t stackValue;

  int countNodes(TreeNode* root) {
    if (root == nullptr) { return 0; }

    bitStack = new BitStack();
    maxDepth = 0;
    stackValue = 0;

    if (recurse(root, 0)) {
      return (1 << maxDepth) - 1 + stackValue + 1;
    }
    else {
      return (1 << (maxDepth + 1)) - 1;
    }
  }

  bool recurse(const TreeNode* node, const int depth) {
    if (node == nullptr) {
      maxDepth = max(maxDepth, depth - 1);
      if (depth - 1 >= maxDepth) {
        maxDepth = depth - 1;
        const auto temp = bitStack->pop();
        stackValue = bitStack->stackValue;
        bitStack->push(temp);
      }
      return depth - 1 < maxDepth;
    }

    bitStack->push(0);
    if (recurse(node->left, depth + 1)) { return true; }
    bitStack->pop();

    bitStack->push(1);
    if (recurse(node->right, depth + 1)) { return true; }
    bitStack->pop();

    return false;
  }
};


#endif // CountCompleteTreeNodes_h__