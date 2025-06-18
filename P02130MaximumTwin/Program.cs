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
    public int PairSum(ListNode head) {
        List<int> vals = [];
        var h = head;
        while(h is not null) {
            vals.Add(h.val);
            h = h.next;
        }
        int ans = 0;

        for(int i = 0; i < vals.Count/2; i++) {
            ans = Math.Max(ans, vals[i] + vals[^(i+1)]);
        }
        return ans;
    }
}
