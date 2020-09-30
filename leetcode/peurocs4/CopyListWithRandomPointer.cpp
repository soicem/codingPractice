#ifndef CopyListWithRandomPointer_h__
#define CopyListWithRandomPointer_h__


#include <vector>
#include <unordered_map>

using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
  Node* copyRandomList(Node* head) {
    unordered_map<Node*, Node*> mappingNodes;

    Node* sourceNode = head;
    Node targetPointNode(0);
    Node* targetPrevious = &targetPointNode;
    while (sourceNode) {
      const auto& targetNode = new Node(sourceNode->val);
      targetNode->random = sourceNode->random;
      targetPrevious->next = targetNode;
      mappingNodes[sourceNode] = targetNode;

      targetPrevious = targetPrevious->next;
      sourceNode = sourceNode->next;
    }

    Node* node = targetPointNode.next;
    while (node) {
      node->random = mappingNodes[node->random];

      node = node->next;
    }

    return targetPointNode.next;
  }
};


#endif // CopyListWithRandomPointer_h__