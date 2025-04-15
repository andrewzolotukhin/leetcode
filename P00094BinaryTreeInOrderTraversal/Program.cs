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
    private void traverse(TreeNode root, IList<int> res) {
        if(root == null) return;
        traverse(root.left, res);
        res.Add(root.val);
        traverse(root.right, res);
    }
    public IList<int> InorderTraversal(TreeNode root) {
        List<int> res = [];
        traverse(root, res);
        return res;
    }
}
