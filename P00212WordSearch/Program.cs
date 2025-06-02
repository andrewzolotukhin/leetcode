public class Solution {

    class Trie {
        public Trie[] Items {get; set;} = new Trie[26];
        public string Word {get; set;} = null;

        public void Add(string s) {
            var node = this;
            foreach(char c in s) {
                int i = c - 'a';
                if(node.Items[i] is null) {
                    node.Items[i] = new();
                }
                node = node.Items[i];
            }
            node.Word = s;
        }
    }

   
    private void AddAll(char[][] board, Trie trie, int x, int y, int left, List<string> result) {
        if(board[x][y] == '0') return;
        if(left <= 0) return;

        char c = board[x][y];
        int ind = board[x][y] - 'a';
        if(trie.Items[ind] is null) return;
        if(trie.Items[ind] is not null && trie.Items[ind].Word is not null) {
            result.Add(trie.Items[ind].Word);
            trie.Items[ind].Word = null;
        }

        int n = board.Length;
        int m = board[0].Length;
        var isInside = (int c1, int c2) => c1 >= 0 && c1 < n && c2 >= 0 && c2 < m;

        List<int> dirs = [0, -1, 0, 1, 0];
        board[x][y] = '0';
        
        for(int i = 0 ; i < 4; i++) {
            int nx = x + dirs[i];
            int ny = y + dirs[i+1];
            if(isInside(nx, ny)) {
                AddAll(board, trie.Items[ind], nx, ny, left - 1, result);
            }
        }
        board[x][y] = c; 
    }

    public IList<string> FindWords(char[][] board, string[] words) {
        var root = new Trie();
        int n = board.Length;
        int m = board[0].Length;
        List<string> ans= [];

        foreach(var s in words) {
            root.Add(s);
        }

        for(int i = 0 ; i < n; i++) {
            HashSet<int> used = new();
            for(int j = 0; j < m; j++) {
                AddAll(board, root, i, j, 10, ans);
            }
        }

        return ans;
    }
}
