#ifndef Remove Nth Node From End Of List_h__
#define Remove Nth Node From End Of List_h__


#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode pointNode(0, head);
    vector<ListNode*> nodes {&pointNode};
    while (nodes.back()->next != nullptr) {
      nodes.push_back(nodes.back()->next);
    }

    const int removeAt = nodes.size() - n;
    nodes[removeAt - 1]->next = nodes[removeAt]->next;

    return pointNode.next;
  }
};


#endif // Remove Nth Node From End Of List_h__