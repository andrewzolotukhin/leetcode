public class Solution {
    List<int> parents = null;
    int n = 0;
    int m = 0;
    int Find(int p) {
        if(parents[p] == p) return p;
        return parents[p] = Find(parents[p]);
    }
    void Union(int s1, int s2) {
        int p1 = Find(s1);
        int p2 = Find(s2);
        if(p1 == -1 || p2 == -1) {
            parents[s1] = parents[s2] = -1;
            return;
        }
        parents[p2] = p1;
    }
    public void Solve(char[][] board) {
        n = board.Length;
        m = board[0].Length;

        parents = Enumerable.Range(0, n*m).ToList();

        var isInside = (int x, int y) => x >= 0 && x < n && y >= 0 && y < m;

        List<(int dx, int dy)> dirs = [(0, 1), (1, 0), (-1, 0), (0, -1)];

        for(int i = 0 ; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] != 'O') continue;
                foreach((int dx, int dy) in dirs) {
                    if(isInside(i + dx, j + dy) && board[i+dx][j+dy] == 'O') {
                        Union(i*m+j, (i+dx)*m+(j+dy));
                    }
                }
            }
        }

        HashSet<int> exclude = new();
        for(int i = 0; i < m; i++) {
            if(board[0][i] == 'O') exclude.Add(Find(i));
            if(board[n-1][i] == 'O') exclude.Add(Find((n-1)*m + i));
        }
        for(int i = 0; i < n; i++) {
            if(board[i][0] == 'O') exclude.Add(Find(m*i));
            if(board[i][m-1] == 'O') exclude.Add(Find(m*(i+1) - 1));
        }
        
        //  foreach(var x in exclude) {
        //      Console.Write($"{x} ");
        //  }
        //  Console.WriteLine();

        for(int i = 0 ; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int p = Find(i*m + j);
                //Console.Write($"{p} ");
                if(board[i][j] != 'O' || exclude.Contains(p)) { 
                    continue; 
                }
            
                board[i][j] = 'X';
            }
            //Console.WriteLine();
        }
    }
}
