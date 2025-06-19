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
    private void Solve(TreeNode node, List<int> seen, long target , ref int ans) {
        if(node is null) return;
        long s = (long)node.val;
        if(s == target) ans++;
        for(int i = 1; i <= seen.Count; i++) {
            s+= seen[^i];
            if(s==target) ans++;
        }
        seen.Add(node.val);
        Solve(node.left, seen, target, ref ans);
        Solve(node.right, seen, target, ref ans);
        seen.RemoveAt(seen.Count - 1);
    }
    public int PathSum(TreeNode root, int targetSum) {
        int ans = 0;
        List<int> seen = [];
        Solve(root, seen, targetSum, ref ans);
        return ans;
    }
}
