public class Solution {
    public bool IsPalindrome(string s) {
        var s2 = string.Join("", s.ToLower().ToCharArray().Where(t => ((t >= 'a' && t <= 'z') || (t >= '0' && t <= '9'))));
        for(int i = 0; i < s2.Length/2; i++) {
            if(s2[i] != s2[s2.Length - 1 - i]) return false;
        }
        return true;
    }
}
