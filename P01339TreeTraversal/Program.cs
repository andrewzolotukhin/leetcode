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
    private int mod = (int)1e9 + 7;
    private Dictionary<TreeNode, int> sums = new();
    
    private int getSums(TreeNode node) {
        if(node is null) return 0;
        int left = getSums(node.left);
        int right = getSums(node.right);

        int total = (int)(((long)node.val + (long)left + (long)right)%mod);
        return sums[node] = total;
    }
    
    public int MaxProduct(TreeNode root) {
        getSums(root);

        int totalSum = sums[root];
        long ans = 0;
        foreach((TreeNode node, int sum) in sums) {
            long r = totalSum - sum;
            ans = Math.Max(ans, r*sum); 
        }

        return (int)(ans % mod);
    }
}
