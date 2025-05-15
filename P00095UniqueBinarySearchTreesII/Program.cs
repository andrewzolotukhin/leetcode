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
    private Dictionary<(int left, int right), IList<TreeNode>> memo = [];
    private IList<TreeNode> Solve(int left, int right) {
        if(left > right) return [null];
        var key = (left, right);
        if(memo.ContainsKey(key)) return memo[key];

        if(left == right) {
            var r = new TreeNode(left);
            return memo[key] = [r];
        }

        List<TreeNode> ans = [];
        for(int i = left; i <= right; i++) {
            var leftTrees = Solve(left, i-1);
            var rightTrees = Solve(i+1, right);
            foreach(var leftT in leftTrees) {
                foreach(var rightT in rightTrees) {
                    ans.Add(new TreeNode(i, leftT, rightT));
                }
            }
        }

        return memo[key] = ans;

    }
    public IList<TreeNode> GenerateTrees(int n) {
        return Solve(1, n);
    }
}
