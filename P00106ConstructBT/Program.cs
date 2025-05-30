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
public class Solution
{
    private TreeNode getNode(int[] inorder, int[] postorder, int ins, int ine, int posts, int poste)
    {
        if (ins>ine || posts > poste)
        {
            return null;
        }

        var node = new TreeNode(postorder[poste]);
        
        int si = ins;
        while(node.val != inorder[si]) si++;

        node.left = getNode(inorder, postorder, ins, si-1, posts, posts+si-ins-1);
        node.right = getNode(inorder, postorder, si+1, ine, posts+si-ins, poste-1);

        return node;
    }

    public TreeNode BuildTree(int[] inorder, int[] postorder)
    {
        return getNode(inorder, postorder, 0, postorder.Length - 1, 0 , postorder.Length - 1);
    }
}
