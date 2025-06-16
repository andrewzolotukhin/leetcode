/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int val=0, ListNode next=null) {
 *         this.val = val;
 *         this.next = next;
 *     }
 * }
 */
public
class Solution {
private
  void Process(List<ListNode> seen, ListNode node) {
    if (node is null)
      return;
    seen.Add(node);
    Process(seen, node.next);
  }
public
  ListNode ReverseList(ListNode head) {
    if (head is null)
      return null;
    List<ListNode> seen = [];
    Process(seen, head);

    for (int i = seen.Count - 1; i >= 0; i--) {
      seen[i].next = null;
      if (i != 0) {
        seen[i].next = seen[i - 1];
      }
    }

    return seen[^1];
  }
}
