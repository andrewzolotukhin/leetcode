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
    public TreeNode solve(int[] nums, int s, int e) {
        if (s > e) return null;
        int mid = s + (e-s)/2;
        var ans = new TreeNode(nums[mid]);
        ans.left = solve(nums, s, mid-1);
        ans.right = solve(nums, mid+1, e);
        return ans;
    }
    public TreeNode SortedArrayToBST(int[] nums) {
        return solve(nums, 0, nums.Length-1);
    }
}
