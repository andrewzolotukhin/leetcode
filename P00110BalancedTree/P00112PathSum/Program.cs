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
    private bool Sol(TreeNode root, int targetSum) {
        if(root is null) return targetSum == 0;
        if(root.left is not null && root.right is not null) {
            return Sol(root.left, targetSum - root.val) || Sol(root.right, targetSum - root.val);
        }
        if(root.left is null && root.right is null) {
            return root.val == targetSum;
        }
        if(root.left is not null) {
            return Sol(root.left, targetSum - root.val);
        } else {
            return Sol(root.right, targetSum - root.val);
        }
    }
    public bool HasPathSum(TreeNode root, int targetSum) {
        if(root is null) return false;
        return Sol(root, targetSum);
    }
}
