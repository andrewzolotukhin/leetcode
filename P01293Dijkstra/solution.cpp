class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int n = grid.size(), m = grid[0].size();

        auto cmp = [&](vector<int>& a, vector<int>& b) { return a[0] > b[0]; };
        auto isInside = [&](int x, int y) {
            return x >= 0 && x < n && y >= 0 && y < m;
        };
        vector<vector<int>> best(n, vector<int>(m, -1));
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);

        pq.push({0, 0, 0, k});
        int ans = INT_MAX;

        while (!pq.empty()) {
            auto t = pq.top();
            pq.pop();
            auto d = t[0];
            auto x = t[1];
            auto y = t[2];
            auto r = t[3];

            if (d > ans)
                continue;

            if (x == n - 1 && y == m - 1) {
                ans = min(d, ans);
                continue;
            }

            for (int j = 0; j < 4; j++) {
                int nx = x + dirs[j].first;
                int ny = y + dirs[j].second;
                if (!isInside(nx, ny))
                    continue;
                int nr = r - grid[nx][ny];
                if (nr < 0)
                    continue;
                if (best[nx][ny] >= nr)
                    continue;
                best[nx][ny] = nr;
                if (grid[nx][ny] && r) {
                    pq.push({d + 1, nx, ny, r - 1});
                }
                if (grid[nx][ny] == 0) {
                    pq.push({d + 1, nx, ny, r});
                }
            }
        }
        if (ans == INT_MAX)
            ans = -1;
        return ans;
    }
};