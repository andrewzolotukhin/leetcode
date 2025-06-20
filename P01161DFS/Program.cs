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
    private void solve(TreeNode node, Dictionary<int, int> sums, int level) {
        if(node is null) return;
        if(sums.ContainsKey(level+1)) {
            sums[level+1]+=node.val;
        } else {
            sums[level+1]=node.val;
        }
        solve(node.left, sums, level+1);
        solve(node.right, sums, level+1);
    }
    public int MaxLevelSum(TreeNode root) {
        Dictionary<int, int> sums = [];
        solve(root, sums, 1);
        int ansV = root.val;
        int ans = 1;
        foreach((int key, int value) in sums) {
            if(ansV < value) {
                ansV = value;
                ans = key-1;
            }
        }
        return ans;
    }
}
