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
    public void Solve(TreeNode root, int depth, List<int> ans) {
        if(root is null) return;
        if(depth >= ans.Count) {
            ans.Add(root.val);
        }

        Solve(root.right, depth + 1, ans);
        Solve(root.left, depth + 1, ans);
    }
    public IList<int> RightSideView(TreeNode root) {
        List<int> ans = [];
        
        Solve(root, 0, ans);

        return ans;
    }
}
