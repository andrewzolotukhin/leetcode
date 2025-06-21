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
    private (TreeNode node, TreeNode parent) Find(TreeNode root, int key, TreeNode parent = null) {
        if(root is null) return (null, parent);
        if(root.val == key) return (root, parent);
        return Find((root.val > key)?root.left:root.right, key, root);
    }
    private void Insert(TreeNode to, TreeNode n) {
        if(n is null) return;
        if(n.val > to.val) {
            if(to.right is null) {
                to.right = n;
            } else {
                Insert(to.right, n);
            }
        } else {
            if(to.left is null) {
                to.left = n;
            } else {
                Insert(to.left, n);
            }
        }
    }
    public TreeNode DeleteNode(TreeNode root, int key) {
        var (n, parent) = Find(root, key);
        if(n is null) return root;
        if(n == root) {
            if(root.left is null && root.right is null) return null;
            if(root.left is not null) {
                Insert(root.left, root.right);
                return root.left;
            } else {
                Insert(root.right, root.left);
                return root.right;
            }
        }

        var newChild = (n.left is not null) ? n.left : n.right;
        var other = (n.left is not null) ? n.right: n.left;
        
        
        if(parent.left == n) {
            parent.left = newChild; 
        }
        else {
            parent.right = newChild;
        }
        
        if(newChild is null) return root;
        Insert(newChild, other);
        
        return root;
    }
}
