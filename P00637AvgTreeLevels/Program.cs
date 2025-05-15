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
    private void Solve(TreeNode root, int depth, List<(long sum, long count)> avgs) {
        if(root is null) return;
        if(depth >= avgs.Count) {
            avgs.Add((0, 0));
        }
        avgs[depth]= (avgs[depth].sum + root.val, avgs[depth].count+1);

        Solve(root.left, depth+1, avgs);
        Solve(root.right, depth+1, avgs);
    }
    public IList<double> AverageOfLevels(TreeNode root) {
        List<(long sum, long count)> avgs = [];

        List<double> ans = [];

        Solve(root, 0, avgs);

        foreach((long sum, long count) in avgs) {
            ans.Add((double)sum/(double)count);
        }
        return ans; 
    }
}
