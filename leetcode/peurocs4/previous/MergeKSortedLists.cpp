#ifndef MergeKSortedLists_h__
#define MergeKSortedLists_h__


#include <vector>
#include <queue>

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
  struct Comparator {
    bool operator()(const ListNode* node1, const ListNode* node2) {
      return node1->val > node2->val;
    }
  };

  ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<ListNode*, vector<ListNode*>, Comparator> pq;

    for (const auto& listNode : lists) {
      if (listNode != nullptr) {
        pq.push(listNode);
      }
    }

    ListNode answer;
    ListNode* node = &answer;

    while (!pq.empty()) {
      ListNode* topNode = pq.top();
      pq.pop();

      node->next = topNode;
      node = node->next;

      if (topNode->next != nullptr) {
        pq.push(topNode->next);
      }
    }

    return answer.next;
  }
};


#endif // MergeKSortedLists_h__