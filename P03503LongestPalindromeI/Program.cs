public class Solution {
    private bool IsPalindrome(string span) {
        //Console.WriteLine(span);
        for(int i = 0 ; i < span.Length/2; i++) {
            if(span[i] != span[span.Length - 1 - i]) return false;
        }
        return true;
    }
    public int LongestPalindrome(string s, string t) {
        int ans = 1;
        for(int s1 = 0; s1 < s.Length; s1++) {
            for(int e1 = s1; e1 <= s.Length; e1++) {
                for(int s2 = 0; s2 < t.Length; s2++) {
                    for(int e2 = s2; e2 <= t.Length; e2++) {
                        if(IsPalindrome(s.Substring(s1, e1-s1) + t.Substring(s2, e2 - s2))) {
                           ans = Math.Max(ans, e1-s1 + e2-s2);   
                        }
                    }
                }
            }
        }
        return ans;
    }
}
