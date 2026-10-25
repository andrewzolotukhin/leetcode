class Solution {
public:
    int closedIsland(auto& grid) {
        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 0)
                    if (i == 0 || i == m - 1 || j == 0 || j == n - 1)
                        grid[i][j] = -1;
                    else
                        grid[i][j] = i * n + j;                

        bool alt = 1;

        while (alt) {
            alt = 0;

            for (int i = 0; i < m; i++)
                for (int j = 0; j < n; j++)
                    if (grid[i][j] != 1) {
                        int v = grid[i][j];

                        if (i > 0 && grid[i - 1][j] != 1)
                            v = min(v, grid[i - 1][j]);

                        if (j > 0 && grid[i][j - 1] != 1)
                            v = min(v, grid[i][j - 1]);

                        if (v != grid[i][j]) {
                            grid[i][j] = v;
                            alt = 1;
                        }
                    }

            for (int i = m - 1; i >= 0; i--)
                for (int j = n - 1; j >= 0; j--)
                    if (grid[i][j] != 1) {
                        int v = grid[i][j];

                        if (i < m - 1 && grid[i + 1][j] != 1)
                            v = min(v, grid[i + 1][j]);

                        if (j < n - 1 && grid[i][j + 1] != 1)
                            v = min(v, grid[i][j + 1]);

                        if (v != grid[i][j]) {
                            grid[i][j] = v;
                            alt = 1;
                        }
                    }
        }

        int res = 0;

        for (int i = 1; i < m - 1; i++)
            for (int j = 1; j < n - 1; j++)
                res += (grid[i][j] == i * n + j);

        return res;
    }
};