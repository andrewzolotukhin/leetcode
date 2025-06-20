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
    private void solve(TreeNode node, bool isLeft, int size, ref int ans) {
        if(node is null) return;
        ans = Math.Max(ans, size);
        if(isLeft) {
            solve(node.right, false, size+1, ref ans);
            solve(node.left, true, 1, ref ans);
        } else {
            solve(node.left, true, size+1, ref ans);
            solve(node.right, false, 1, ref ans);
        }
    }
    public int LongestZigZag(TreeNode root) {
        int ans = 0;
        if(root is null) return 0;
        solve(root, true, 0, ref ans);
        solve(root, false, 0, ref ans);
        return ans;
    }
}
