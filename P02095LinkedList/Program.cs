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
    public ListNode DeleteMiddle(ListNode head) {
        if(head is null) return null;
        int c = 0;
        var h = head;
        while(h is not null) {
            c++;
            h = h.next;
        }

        if(c == 1) return null;
        
        int m = c / 2;

        int i = 1;
        h = head;
        while(i < m) {
            i++;
            h = h.next;
        }
        
        if(h is not null) {
            if(h.next is not null) {
                if(h.next.next is not null) {
                    h.next = h.next.next;
                } else {
                    h.next = null;
                }
            }
        }

        return head;
    }
}
