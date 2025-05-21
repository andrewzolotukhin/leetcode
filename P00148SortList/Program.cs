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
    public ListNode SortList(ListNode head) {
        List<int> vals = [];
        var h = head;

        while(h is not null) {
            vals.Add(h.val);
            h = h.next;
        }

        vals.Sort();

        ListNode res = new();
        var end = res;

        foreach(var el in vals) {
            end.next = new ListNode(el);
            end = end.next;
        }


        return res.next;
    }
}
