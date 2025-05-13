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
    public int CountNodes(TreeNode root) {
        if(root is null) return 0;
        int depth = 0;
        var rr = root;
        while(rr is not null) {
            depth++;
            rr = rr.left;
        }
        if(depth == 1) return 1;

        int n = (1 << depth) - 1;
        int ans = 0;
        int l = 0;
        int r = (1 << (depth-1));
        while(l < r) {
            int mid = (l+r)/2;

            int d = depth;
            rr = root;

            //Console.WriteLine($"mid: {mid}");
            while(d > 1) {
                //Console.Write($"val: {rr.val} ");
                if(((mid & (1 << (d-2))) > 0)) {
                    //Console.Write("right ");
                    rr = rr.right;
                } else {
                    //Console.Write("left ");
                    rr = rr.left;
                }
                if(rr is null) break;
                d--;
            }
            //Console.WriteLine("");
            if(rr is not null) {
                l = mid + 1;
            } else {
                r = mid;
            }

            //Console.Write($"new: {l}, {r} ");
        }
        return (1 << (depth-1)) - 1 + l;
    }
}
