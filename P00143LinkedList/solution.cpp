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
  void reorderList(ListNode *head) {
    deque<ListNode *> q;
    auto h = head;
    while (h != nullptr) {
      q.push_back(h);
      h = h->next;
    }

    auto tail = q.front();
    q.pop_front();

    while (!q.empty()) {
      auto last = q.back();
      q.pop_back();
      last->next = nullptr;
      tail->next = last;
      tail = tail->next;

      if (!q.empty()) {
        auto first = q.front();
        q.pop_front();
        first->next = nullptr;
        tail->next = first;
        tail = tail->next;
      }
    }
  }
};
