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
    private int i = 0;
    private TreeNode Solve(int[] preorder, int bound) {
        if(i == preorder.Length || preorder[i] > bound) return null;
        var root = new TreeNode(preorder[i++]);
        root.left = Solve(preorder, root.val);
        root.right = Solve(preorder, bound);
        return root;
    }
    public TreeNode BstFromPreorder(int[] preorder) {
        return Solve(preorder, int.MaxValue);
    }
}
