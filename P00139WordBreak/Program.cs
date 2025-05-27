public class Solution {
    HashSet<string> Words = new();
    Dictionary<int, bool> Memo = new();

    public bool Solve(string s, int start) {
        if(Memo.ContainsKey(start)) return Memo[start];
        if(start == s.Length) return Memo[start] = true;

        var span = s.AsSpan(start);
        int spanL = span.Length;
        foreach(var word in Words.Where(w => w.Length <= spanL)) {
            if(word.AsSpan().Equals(span.Slice(0, word.Length), StringComparison.Ordinal)) {
                if(Solve(s, start + word.Length)) {
                    return Memo[start] = true;
                }
            }
        }

        return Memo[start] = false;
    }

    public bool WordBreak(string s, IList<string> wordDict) {
        foreach(var w in wordDict) Words.Add(w);

        return Solve(s, 0);
    }
}
