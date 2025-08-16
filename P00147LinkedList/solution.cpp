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
  ListNode *insertionSortList(ListNode *head) {
    auto nhead = new ListNode(INT_MIN);

    auto curr = head;

    while (curr != nullptr) {
      auto prev = nhead;
      while (prev->next != nullptr && prev->next->val <= curr->val) {
        prev = prev->next;
      }
      auto next = curr->next;
      curr->next = prev->next;
      prev->next = curr;
      curr = next;
    }

    return nhead->next;
  }
};
