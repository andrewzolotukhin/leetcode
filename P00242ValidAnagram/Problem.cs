public class Solution {
    public bool IsAnagram(string s, string t) {
        Dictionary<char, int> freq1 = new(), freq2 = new();
        foreach(char c in s) if(freq1.ContainsKey(c)) freq1[c]++; else freq1[c] = 1;
        foreach(char c in t) if(freq2.ContainsKey(c)) freq2[c]++; else freq2[c] = 1;
        if(freq1.Count != freq2.Count) return false;

        foreach((char key, int value) in freq1) {
            if(!(freq2.ContainsKey(key) && freq2[key] == value)) return false;
        }
        return true;
    }
}
