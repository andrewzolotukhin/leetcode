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
    private void traverse(TreeNode node, int depth, IList<IList<int>> ans) {
        if(node is null) return;
        if(ans.Count - 1 < depth) {
            ans.Insert(0, [node.val]);
        } else {
            ans[ans.Count - 1 - depth].Add(node.val);
        }
        traverse(node.left, depth+1, ans);
        traverse(node.right,depth+1, ans);
    }
    public IList<IList<int>> LevelOrderBottom(TreeNode root) {
        List<IList<int>> ans = [];

        traverse(root, 0, ans);

        return ans;
    }
}
