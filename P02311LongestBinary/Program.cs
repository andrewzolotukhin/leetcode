public class Solution {
    public int LongestSubsequence(string s, int k) {
        
        int sm = 0;
        int ans = 0;
        int bits = (int)(Math.Log(k, 2)) + 1;
        for (int i = 0; i < s.Length; i++) {
            char e = s[s.Length - 1 - i];
            if (e == '1') {
                if (i < bits && sm + (1 << i) <= k) {
                    sm += 1 << i;
                    ans++;
                }
            } else {
                ans++;
            }
        }
        return ans;
    }
}
