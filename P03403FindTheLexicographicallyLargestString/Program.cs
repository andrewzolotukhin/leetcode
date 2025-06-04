public class Solution {
    public string AnswerString(string word, int numFriends) {
        if(numFriends == 1) return word;
        ReadOnlySpan<char> ans = "".AsSpan();
        for(int i = 0 ; i < word.Length; i++) {
            var s = word.AsSpan(i, Math.Min(word.Length - numFriends + 1, word.Length - i));
            if(ans.CompareTo(s, StringComparison.Ordinal) <= 0) ans = s;
        }
        return ans.ToString();
    }
}
