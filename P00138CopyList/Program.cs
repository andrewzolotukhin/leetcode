/*
// Definition for a Node.
public class Node {
    public int val;
    public Node next;
    public Node random;
    
    public Node(int _val) {
        val = _val;
        next = null;
        random = null;
    }
}
*/

public class Solution {
    public Node CopyRandomList(Node head) {
        if(head is null) return null;

        var newHead = new Node(head.val);
        Dictionary<Node, Node> map = new();
        map[head] = newHead;

        var current = head.next;
        var last = newHead;

        while(current is not null) {
            last.next = new(current.val);
            map[current] = last.next;
            last = last.next;
            current = current.next;
        }

        current = head;

        while(current is not null) {
            if(current.random is not null) {
                map[current].random = map[current.random];
            }
            
            current = current.next;
        }

        return newHead;
    }
}
