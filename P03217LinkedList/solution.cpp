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
  ListNode *modifiedList(vector<int> &nums, ListNode *head) {
    unordered_set<int> m;
    for (auto &v : nums)
      m.insert(v);

    auto h = new ListNode();
    auto tail = h;

    auto curr = head;

    while (curr != nullptr) {
      auto n = curr->next;
      if (m.count(curr->val) == 0) {
        curr->next = nullptr;
        tail->next = curr;
        tail = tail->next;
      }
      curr = n;
    }
    return h->next;
  }
};
