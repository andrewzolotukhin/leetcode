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
    public ListNode Partition(ListNode head, int x) {
        var list1 = new ListNode();
        var list2 = new ListNode();
        var list1Tail = list1;
        var list2Tail = list2;

        var curr = head;

        while(head != null) {
            if(head.val < x) {
                list1Tail.next = head;
                list1Tail = head;
            } else {
                list2Tail.next = head;
                list2Tail = head;
            }
            head = head.next;
            list1Tail.next = null;
            list2Tail.next = null;
        }

        if(list1.next != null && list2.next != null) {
            list1Tail.next = list2.next;
            return list1.next;
        }

        if(list1.next == null) {
            return list2.next;
        }

        return list1.next;
    }
}
