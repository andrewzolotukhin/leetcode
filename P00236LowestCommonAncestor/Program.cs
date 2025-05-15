/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    private bool FindNode(TreeNode root, TreeNode needle, List<TreeNode> path) {
        if(root is null) return false;
        path.Add(root);
        if(root == needle) return true;
        if(FindNode(root.left, needle, path) || FindNode(root.right, needle, path)) {
            return true;
        }
        path.RemoveAt(path.Count - 1);
        return false;
    }
    public TreeNode LowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        List<TreeNode> listP = [], listQ = [];
        FindNode(root, p, listP);
        FindNode(root, q, listQ);

        int i = 0;
        while(i < Math.Min(listP.Count, listQ.Count) && listP[i] == listQ[i]) i++;

        return listP[i-1];
    }
}
