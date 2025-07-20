public class Solution {

    public class Trie {
        public string Hash {get; set;} = string.Empty;
        public Dictionary<string, Trie> Children {get;} = [];
    }

    public IList<IList<string>> DeleteDuplicateFolder(IList<IList<string>> paths) {
        var root = new Trie();

        foreach(var p in paths) {
            var current = root;
            foreach(var n in p) {
                if(!current.Children.ContainsKey(n)) {
                    current.Children[n] = new();
                }
                current = current.Children[n];
            }
        }

        var uniq = new Dictionary<string, int>();

        void Construct(Trie trie) {
            if(trie.Children.Count == 0) return;

            var values = new List<string>();


            foreach((string key, Trie t) in trie.Children) {
                Construct(t);
                values.Add($"{key}[{t.Hash}]");
            }
            values.Sort();

            trie.Hash = string.Join("", values);

            if(!uniq.ContainsKey(trie.Hash)) {
                uniq[trie.Hash] = 0;
            }
            uniq[trie.Hash]++;
        }

        Construct(root);


        var ans = new List<IList<string>>();
        var path = new List<string>();

        void Solve(Trie trie) {
            if(uniq.ContainsKey(trie.Hash) && uniq[trie.Hash] > 1) {
                return;
            }

            if(path.Count > 0) {
                ans.Add(new List<string>(path));
            }

            foreach((string key, Trie value) in trie.Children) {
                path.Add(key);
                Solve(value);
                path.RemoveAt(path.Count-1);
            }
        }

        Solve(root);

        return ans;
    }
}
