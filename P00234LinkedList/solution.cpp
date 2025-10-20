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
  bool isPalindrome(ListNode *head) {
    auto slow = head, fast = head;

    if (!head || !head->next)
      return true;

    ListNode *prev = nullptr;

    while (fast && fast->next) {
      fast = fast->next->next;
      auto next = slow->next;
      slow->next = prev;
      prev = slow;
      slow = next;
    }
    if (fast)
      slow = slow->next;
    auto left = prev, right = slow;

    while (left != nullptr && right != nullptr) {
      if (left->val != right->val) {
        return false;
      }
      left = left->next;
      right = right->next;
    }

    return true;
  }
};
