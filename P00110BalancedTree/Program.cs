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
    private int GetDepth(TreeNode root) {
        if(root is null) return 0;
        if(root.left is null && root.right is null) return 1;
        return Math.Max(GetDepth(root.left), GetDepth(root.right)) + 1;
    }
    public bool IsBalanced(TreeNode root) {
        if(root is null) return true;
        return Math.Abs(GetDepth(root.left) - GetDepth(root.right)) <= 1 && IsBalanced(root.left) && IsBalanced(root.right);
    }
}
