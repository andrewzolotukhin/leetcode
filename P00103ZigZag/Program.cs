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
    private void Solve(TreeNode root, int depth, IList<IList<int>> ans) {
        if(root is null) return;
        if(depth >= ans.Count) {
            ans.Add([root.val]);
        } else {
            ans[depth].Add(root.val);
        }
        Solve(root.left, depth+1, ans);
        Solve(root.right, depth+1, ans);
    }
    public IList<IList<int>> ZigzagLevelOrder(TreeNode root) {
        List<IList<int>> ans = [];

        Solve(root, 0, ans);

        for(int i = 1; i < ans.Count; i+=2) {
            ans[i] = ans[i].Reverse().ToList();
        }
        return ans;
    }
}
