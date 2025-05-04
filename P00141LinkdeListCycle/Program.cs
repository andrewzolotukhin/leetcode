/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public bool HasCycle(ListNode head) {
        Dictionary<ListNode, bool> memo = new();

        var current = head;
        while(current is not null) {
            if(memo.ContainsKey(current)) return true;
            memo[current] = true;
            current = current.next;
        }
        return false;
    }
}
