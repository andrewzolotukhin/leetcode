public class Solution {
    public bool WordPattern(string pattern, string s) {
        List<string> words = s.Split(" ").ToList();
        Dictionary<char, int> m1 = new();
        Dictionary<string, int> m2 = new();
        if(words.Count != pattern.Length) return false;

        for(int i = 0 ; i < pattern.Length; i++) {
            if(m1.ContainsKey(pattern[i]) ^ m2.ContainsKey(words[i])) return false;
            if(m1.ContainsKey(pattern[i]) && m2.ContainsKey(words[i])) {
                if(m1[pattern[i]] != m2[words[i]]) return false;
            } else {
                m1[pattern[i]] = i + 1;
                m2[words[i]] = i + 1;
            }
        }

        return true;
    }
}
