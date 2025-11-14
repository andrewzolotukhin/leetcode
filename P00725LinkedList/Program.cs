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
    public ListNode[] SplitListToParts(ListNode head, int k) {
        int len = 0;
        var h = head;
        while(h is not null) {
            len++;
            h=h.next;
        }

        int size = len/k, rem = len%k;
        var node = head;

        List<ListNode> ans = [];

        for(int i = 0; node is not null && i < k; i++) {
            ans.Add(node);
            ListNode prev = null;
            for(int j = 0; j < (size+((rem>0)?1:0));j++) {
                prev = node;
                node = node.next;
            }
            prev.next = null;
            rem--;
        }

        while(ans.Count < k) {
            ans.Add(null);
        }


        return ans.ToArray();
    }
}
