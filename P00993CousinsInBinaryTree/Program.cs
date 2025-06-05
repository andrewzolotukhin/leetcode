/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int val=0, TreeNode left=null, TreeNode right=null) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
public class Solution {
    private (int depth, TreeNode node) FindParent(TreeNode node, int val, int depth = 0, TreeNode parent = null, int maxDepth = -1) {
        if(node.val == val) return (depth, parent);
        if(maxDepth != -1 && depth > maxDepth) return (-1, null);

        if(node.left is not null) {
            var pl = FindParent(node.left, val, depth+1, node);
            if(pl.depth != -1) return pl;
        }

        if(node.right is not null) {
            var pr = FindParent(node.right, val, depth+1, node);
            if(pr.depth != -1) return pr;
        }

        return (-1, null);
    }
    public bool IsCousins(TreeNode root, int x, int y) {
        var p1 = FindParent(root, x);
        var p2 = FindParent(root, y, maxDepth: p1.depth);
        return p1.depth == p2.depth && p1.node != p2.node;
    }
}
