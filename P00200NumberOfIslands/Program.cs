public class Solution {
    private List<int> parents = null;
    private int Find(int s) {
        if(parents[s] == s) return s;
        return parents[s] = Find(parents[s]);
    }
    private void Union(int s1, int s2) {
        int p1 = Find(s1);
        int p2 = Find(s2);
        if(p1 == p2) return;
        parents[p2] = p1;
    }
    public int NumIslands(char[][] grid) {
        int n = grid.Length;
        int m = grid[0].Length;
        parents = Enumerable.Range(0, n*m).ToList();
        List<(int dx, int dy)> dirs = [(1, 0), (0, 1)];
        var isInside = (int x, int y) => x >= 0 && x < n && y >= 0 && y < m;

        for(int x = 0; x < n; x++) {
            for(int y = 0; y < m; y++) {
                if(grid[x][y] != '1') continue;
                foreach((int dx, int dy) in dirs) {
                    int nx = x + dx;
                    int ny = y + dy;
                    if(isInside(nx, ny) && grid[nx][ny] == '1') {
                        Union(x*m+y, nx*m+ny);
                    }
                }
            }
        }

        HashSet<int> ans = new();

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == '1') {
                    ans.Add(Find(i*m+j));
                }
            }
        }

        return ans.Count;
    }
}
