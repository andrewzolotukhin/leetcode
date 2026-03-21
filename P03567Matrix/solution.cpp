class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> ans(n - k + 1, vector<int>(m - k + 1, 0));
        for (int i = 0; i < n - k + 1; i++) {
            for (int j = 0; j < m - k + 1; j++) {
                vector<int> r;
                for (int l = i; l < i + k; l++) {
                    for (int o = j; o < j + k; o++) {
                        r.push_back(grid[l][o]);
                    }
                }
                sort(r.begin(), r.end());
                int rr = INT_MAX;
                for (int p = 1; p < r.size(); p++) {
                    if (r[p] == r[p - 1])
                        continue;
                    rr = min(rr, r[p] - r[p - 1]);
                }
                ans[i][j] = rr == INT_MAX ? 0 : rr;
            }
        }
        return ans;
    }
};