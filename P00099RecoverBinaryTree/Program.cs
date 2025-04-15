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
    private void recover(TreeNode node, ref TreeNode start, ref TreeNode end, ref TreeNode prev) {
        if(node == null) {
            return;
        }
        recover(node.left, ref start, ref end, ref prev);
        if(prev != null) {
            if(node.val < prev.val) {
                if(start == null) {
                    start = prev;
                }
                end = node;
            }
        }
        prev = node;
        recover(node.right, ref start, ref end, ref prev);
    }

    public void RecoverTree(TreeNode root) {
        TreeNode start = null, end = null, prev = null;
        recover(root, ref start, ref end, ref prev);
        var t = start.val;
        start.val = end.val;
        end.val = t;
    }
}
