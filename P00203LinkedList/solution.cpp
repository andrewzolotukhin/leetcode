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
  ListNode *removeElements(ListNode *head, int val) {
    ListNode *h = new ListNode();
    h->next = head;

    auto curr = h;

    while (curr->next != nullptr) {
      if (curr->next->val == val) {
        curr->next = curr->next->next;
        continue;
      }
      curr = curr->next;
    }

    return h->next;
  }
};
