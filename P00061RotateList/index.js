/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} k
 * @return {ListNode}
 */
var rotateRight = function (head, k) {
  if (!head) return head;
  let first = head;
  let last = head;
  let nodes = [];
  nodes.push(last);

  while (last.next) {
    last = last.next;
    nodes.push(last);
  }

  if (nodes.length == 1) return head;

  let newFirst = (k % nodes.length) == 0 ? 0 : (nodes.length - k % nodes.length);
  let newLast = (k % nodes.length) == 0 ? (nodes.length - 1) : ((newFirst - 1 + nodes.length) % nodes.length);

  if (newFirst != 0) {
    last.next = head;
    nodes[newLast].next = null;
  } else {
    return head;
  }

  return nodes[newFirst];
};
