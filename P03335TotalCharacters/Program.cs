public class Solution {
    private int mod  = (int)1e9 + 7;
    private int[] memo = new int[100100];
    private int GetCount(int t) {
        if(memo[t] != 0) return memo[t];
        if('a' + t <= 'z') {
            memo[t] = 1;
            return memo[t];
        } 
        return memo[t] = (int)((long)(GetCount(t - 26) + GetCount(t - 25)))%mod;
    }
    public int LengthAfterTransformations(string s, int t) {
        long ans = 0;
        foreach(char c in s) 
        {
            ans = (ans + GetCount(t+(int)(c-'a')))%mod;
        }
        return (int)ans;
    }
}
