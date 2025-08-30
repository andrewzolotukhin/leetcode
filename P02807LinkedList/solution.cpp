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
  ListNode *insertGreatestCommonDivisors(ListNode *head) {
    auto curr = head;

    while (curr != nullptr && curr->next != nullptr) {
      auto g = new ListNode(gcd(curr->val, curr->next->val));
      g->next = curr->next;
      curr->next = g;

      curr = g->next;
    }

    return head;
  }
};
