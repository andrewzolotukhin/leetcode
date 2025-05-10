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
    private void Solve(TreeNode root, int curr, ref int ans) {
        if(root is null) {
            ans += curr;
            return;
        }

        curr = curr*10 + root.val;

        if(root.left is not null) {
            Solve(root.left, curr, ref ans);
        }
        if (root.right is not null) {
            Solve(root.right, curr, ref ans);
        }

        if(root.left is null && root.right is null) {
            ans+= curr;
            return;
        }
    }
    public int SumNumbers(TreeNode root) {
        int ans = 0;
        Solve(root, 0, ref ans);
        return ans;
    }
}
