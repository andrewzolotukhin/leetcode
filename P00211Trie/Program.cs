public class WordDictionary {

    class Item {
        public Item[] Items {get; set;} = new Item[26];
        public bool HasEnd {get; set;} = false;
        public bool Match(string s, int index = 0) {
            if(index > s.Length-1) return HasEnd;
            bool ans = false;

            if(s[index] == '.') {
                for(int i = 0 ; i < 26; i++) {
                    if(Items[i] is not null) {
                        ans |= Items[i].Match(s, index+1);
                        if(ans) return true;
                    }
                }
                return ans;
            } else {
                int i = s[index] - 'a';
                if(Items[i] is null) return false;
                return Items[i].Match(s, index+1);
            }
        }
    }

    private Item root = new Item();

    public WordDictionary() {
        
    }
    
    public void AddWord(string word) {
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
        return root.Match(word);
    }
}

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.AddWord(word);
 * bool param_2 = obj.Search(word);
 */
