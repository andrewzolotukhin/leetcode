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
    public bool Solve(TreeNode? root, TreeNode? comp) {
        if(root is null && comp is null) return true;
        if(root is null || comp is null) return false;
        if(root.val != comp.val) return false;

        return Solve(root.left, comp.right) && Solve(root.right, comp.left);
    }
    public bool IsSymmetric(TreeNode root) {
        if(root is null) return true;
        return Solve(root.left, root.right);
    }
}
