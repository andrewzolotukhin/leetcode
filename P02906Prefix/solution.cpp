class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> prefix(n * m + 1, 1), postfix(n * m + 1, 1);

        for (int i = 0, k = 1; i < n; i++) {
            for (int j = 0; j < m; j++, k++) {
                int val = grid[i][j] % 12345;
                prefix[k] = (prefix[k - 1] * val) % 12345;
            }
        }

        vector<vector<int>> ans(n, vector<int>(m,0));

        for (int i = n*m - 1; i >= 0; i--) {
            int r = i / m, c = i % m;
            int val = grid[r][c] % 12345;
            postfix[i] = (postfix[i + 1] * val) % 12345;
        }

        for (int i = 0, l = 1; i < n; i++) {
            for (int j = 0; j < m; j++, l++) {
                ans[i][j] = ((prefix[l - 1] * postfix[l])) % 12345;
            }
        }
        return ans;
    }
};