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
    private int getMaxDepth(TreeNode root, int depth, ref int maxDepth, ref TreeNode result) {
        if(root.left == null && root.right == null) {
            if(maxDepth < depth) {
                maxDepth = depth;
                result = root;
            }
            return depth;
        }

        int left = root.left == null ? depth : getMaxDepth(root.left, depth+1, ref maxDepth, ref result);
        int right = root.right == null ? depth : getMaxDepth(root.right, depth+1, ref maxDepth, ref result);

        if(left == right && maxDepth <= left) {
            maxDepth = left;
            result = root;
        }
        return left > right ? left : right;
    }
    public TreeNode LcaDeepestLeaves(TreeNode root) {
        TreeNode res = null;
        int maxDepth = -1;
        getMaxDepth(root, 0, ref maxDepth, ref res);
        if(res == null) return root;
        return res; 
    }
}
