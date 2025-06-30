public class Solution {
    private class Trie {
        public Trie[] Children = new Trie[26];
        private string? Word;
        
        public void Add(string s, int index = 0) {
            if(index >= s.Length) {
                Word = s;
                return;
            }
            int c = s[index] - 'a';
            if(Children[c] is null) {
                Children[c] = new Trie();
            }
            Children[c].Add(s, index+1);
        }

        public IEnumerable<string> Iterate(string prefix) {
            if(Word is not null) {
                yield return prefix;
            }
            for(char c = 'a'; c <= 'z'; c++) {
                if(Children[c-'a'] is null) continue;
                foreach(var cr in Children[c-'a'].Iterate(prefix+c.ToString())) {
                    yield return cr;
                }
            }
        }
    }
    public IList<IList<string>> SuggestedProducts(string[] products, string searchWord) {
        var trie = new Trie();
        foreach (var p in products) trie.Add(p);

        List<IList<string>> ans = new();
        string sr = string.Empty;

        foreach (var sw in searchWord) {
            sr += sw;
            trie = trie?.Children[sw - 'a'];

            var ae = new List<string>();
            if (trie != null) {
                foreach (var a in trie.Iterate(sr)) {
                    ae.Add(a);
                    if (ae.Count == 3) break;
                }
            }
            ans.Add(ae);
        }

        return ans;
    }
}
