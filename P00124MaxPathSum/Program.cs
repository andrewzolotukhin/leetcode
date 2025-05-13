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
    Dictionary<TreeNode, int> memo = new();
    int ans = -100000000;
    public int Process(TreeNode root) {
        if(root is null) return 0;
        if(memo.ContainsKey(root)) return memo[root];
        
        int left = Process(root.left);
        int right = Process(root.right);
        
        memo[root] = Math.Max(Math.Max(left, right) + root.val, root.val);
        return memo[root];
    }
    private int Final(TreeNode root) {
        if(root is null) return 0;
        Final(root.left);
        Final(root.right);
        ans = Math.Max(memo[root], ans);
        ans = Math.Max(ans, root.val);

        if(root.left is not null && root.right is not null) {
            ans = Math.Max(ans, memo[root.right] + memo[root.left] + root.val);
        }
        return ans;
    }
    public int MaxPathSum(TreeNode root) {
        Process(root);
        return Final(root);
    }
}
