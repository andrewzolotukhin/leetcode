/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
  ListNode *mergeNodes(ListNode *head) {
    auto t = head->next;
    auto ansH = head;
    auto ansT = ansH;

    while (t != nullptr) {
      int acc = 0;
      while (t->val) {
        acc += t->val;
        t = t->next;
      }
      if (acc) {
        ansT->next = new ListNode(acc);
        ansT = ansT->next;
      }
      // ansT->next = new ListNode(0);
      // ansT = ansT->next;
      t = t->next;
    }

    return ansH->next;
  }
};
