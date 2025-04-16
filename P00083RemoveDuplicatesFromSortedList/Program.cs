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
    public ListNode DeleteDuplicates(ListNode head) {
        if(head == null) return head;
        ListNode last = head;
        ListNode curr = head.next;

        while(curr != null) {
            if(last.val != curr.val) {
              last.next = curr;
              last = curr;
            }
            curr = curr.next;
        }

        last.next = null;

        return head;
    }
}
