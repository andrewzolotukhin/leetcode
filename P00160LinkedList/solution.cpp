/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    unordered_set<ListNode *> s;
    auto l = headA, r = headB;

    while (l != nullptr || r != nullptr) {
      if (l != nullptr) {
        if (s.count(l))
          return l;
        s.insert(l);
        l = l->next;
      }
      if (r != nullptr) {
        if (s.count(r))
          return r;
        s.insert(r);
        r = r->next;
      }
    }
    return nullptr;
  }
};
