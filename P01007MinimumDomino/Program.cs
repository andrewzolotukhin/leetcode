public class Solution {
    public int MinDominoRotations(int[] tops, int[] bottoms) {
        int n = tops.Length;
        int ans = n;
        bool t = false;

        for(int i = 1; i <= 6; i++) {
            BitArray bst = new(n), bsb = new(n);
            for(int j = 0; j < n; j++) {
                bst[j] = tops[j] == i;
                bsb[j] = bottoms[j] == i;
            }
            var bsts = bst.Cast<bool>().Count(b => b);
            bst.Or(bsb);
            if(bst.Cast<bool>().Count(b => b) == n) {
                t = true;
                ans = Math.Min(ans,(int)(n - Math.Max(bsts, bsb.Cast<bool>().Count(b => b))));
            }
        }

        if(!t) return -1;
        return ans;
    }
}
