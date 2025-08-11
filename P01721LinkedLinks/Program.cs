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
    public ListNode SwapNodes(ListNode head, int k) {
         if (head == null || head.next == null) return head;

        var fast = head;
        var slow = head;
        ListNode first = null;

        for (int i = 1; i < k; i++) {
            fast = fast.next;
        }

        first = fast;

        while (fast.next != null) {
            fast = fast.next;
            slow = slow.next;
        }

        var second = slow;

        int temp = first.val;
        first.val = second.val;
        second.val = temp;

        return head;
    }
}
