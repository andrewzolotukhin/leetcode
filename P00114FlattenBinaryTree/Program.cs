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
    private void Solve(TreeNode root, ref TreeNode last) {
        if(root is null) return;

        last.right = root;
        last = root;

        var l = root.left;
        var r = root.right;
        root.left = null;
        root.right = null;
        Solve(l, ref last);
        Solve(r, ref last);
    }

    public void Flatten(TreeNode root) {
        if(root is null) return;

        var newRoot = new TreeNode();
        var last = newRoot;
        Solve(root, ref last);
    }
}
