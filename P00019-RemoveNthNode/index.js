/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} n
 * @return {ListNode}
 */
var removeNthFromEnd = function (head, n) {
  const getLength = (l) => {
    let r = 0;
    while (l) {
      r++;
      l = l.next;
    }
    return r;
  };

  const getKth = (l, k) => {
    let r = 0;
    if (k < 0) return null;
    while (l) {
      r++;
      if (r == k) return l;
      l = l.next;
    }
    return null;
  };

  if (!head) return head;

  const ll = getLength(head);
  const ei = ll - n;

  if (ei <= 0) {
    return head.next;
  }

  const prev = getKth(head, ei);
  const curr = prev ? prev.next : null;
  if (prev) prev.next = curr ? curr.next : null;

  return head;
};
