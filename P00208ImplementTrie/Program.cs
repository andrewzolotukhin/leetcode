public class Trie {

    class Item {
        public bool HasEnd {get; set;} = false;
        public Item[] Items = new Item[26];

        public bool Contains(string s, int index = 0) {
            if(index == s.Length) return true;
            int i = s[index] - 'a';
            return Items[i] is not null && Items[i].Contains(s, index + 1);
        }

        public bool ContainsAll(string s, int index = 0) {
            if(index == s.Length) return HasEnd;
            int i = s[index] - 'a';
            return Items[i] is not null && Items[i].ContainsAll(s, index + 1);
        }
    }

    private Item root;

    public Trie() {
        root = new Item();
    }
    
    public void Insert(string word) {
        var r = root;
        foreach(char c in word) {
            int index = c - 'a';
            if(r.Items[index] is null) {
                r.Items[index] = new Item();
            }
            r = r.Items[index];
        }
        r.HasEnd = true;
    }
    
    public bool Search(string word) {
        return root.ContainsAll(word);
    }
    
    public bool StartsWith(string prefix) {
        return root.Contains(prefix);
    }
}

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.Insert(word);
 * bool param_2 = obj.Search(word);
 * bool param_3 = obj.StartsWith(prefix);
 */
