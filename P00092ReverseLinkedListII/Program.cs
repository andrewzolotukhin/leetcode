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
public class Solution {
    private void reverse(ListNode node, int index, int left, int right, List<int> vals) {
        if(node == null) return;
        if(index > right) return;
        if(index >= left) vals.Add(node.val);
        reverse(node.next, index+1, left, right, vals);
        if(vals.Count == 0) return;
        node.val = vals[0];
        vals.RemoveAt(0);
    }
    public ListNode ReverseBetween(ListNode head, int left, int right) {
        reverse(head, 1, left, right, []);
        return head;
    }
}
