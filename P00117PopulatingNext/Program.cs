/*
// Definition for a Node.
public class Node {
    public int val;
    public Node left;
    public Node right;
    public Node next;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, Node _left, Node _right, Node _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
}
*/

public
class Solution {
private void Solve(Node? root, Dictionary<int, Node> neigh, int level) {
    if (root is null) {
      return;
    }

    Solve(root.right, neigh, level + 1);
    Solve(root.left, neigh, level + 1);

    if (neigh.ContainsKey(level)) {
      root.next = neigh[level];
    }
    neigh[level] = root;
  }
public
  Node Connect(Node root) {
    if (root is null)
      return root;
    Dictionary<int, Node> neigh = new ();

    Solve(root, neigh, 0);

    return root;
  }
}
