public class Solution {

    private class Trie {
        public bool IsLeaf {get; set;} = false;

        public Dictionary<string, Trie> Children {get; set;} = new();
    }


    public IList<string> RemoveSubfolders(string[] folder) {
        var root = new Trie();

        foreach(var s in folder) {
            var current = root;
            var names = s.Split('/', StringSplitOptions.RemoveEmptyEntries);

            foreach(var n in names) {
                if(!current.Children.ContainsKey(n)) {
                    current.Children[n] = new();
                }
                current = current.Children[n];
            }

            current.IsLeaf = true;
        }

        List<string> ans = [];

        foreach(var p in folder) {
            var current = root;

            var names = p.Split('/', StringSplitOptions.RemoveEmptyEntries);
            var isLeaf = false;

            for(int i = 0; i < names.Length; i++) {
                var next = current.Children[names[i]];

                if(next.IsLeaf && i != names.Length-1) {
                    isLeaf = true;
                    break;
                }

                current = next;
            }
            if(!isLeaf) ans.Add(p);
        }

        return ans;
    }
}
