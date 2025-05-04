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
        if(head is null) return head;

        Dictionary<int, int> freq = new();

        var nh = head;
        while(nh is not null) {
            if(freq.ContainsKey(nh.val)) {
                freq[nh.val]++;
            } else {
                freq[nh.val] = 1;
            }
            nh = nh.next;
        }

        nh = new ListNode(0);

        var last = nh;

        var curr = head;

        while(curr is not null) {
            var n = curr.next;
            if(freq[curr.val] == 1) {
                last.next = curr;
                last.next.next = null;
                last = last.next;
            }
            curr = n;
        }


        return nh.next;
    }
}
