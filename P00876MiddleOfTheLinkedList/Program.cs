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
    private void Find(ListNode node, ref int size, ref ListNode result) {
        int s = size + 1;
        if(node.next != null) {
            size++;
            Find(node.next, ref size, ref result);
        }
        if(size %2 ==0 && s == size/2+1) {
            result = node;
        } else if(size %2==1 && s == (size+1)/2+1) {
            result = node;
        }
    }
    public ListNode MiddleNode(ListNode head) {
        ListNode r = null;
        int size = 0;
        Find(head, ref size, ref r);
        return r;
    }
}
