class Solution {
public:
  int minAreaRect(vector<vector<int>> &points) {
    int ans = INT_MAX, n = points.size();

    unordered_set<long long> m;
    for (auto p : points) {
      m.insert(((long long)p[0] << 20) | p[1]);
    }

    for (int i = 0; i < n; i++) {
      int x1 = points[i][0], y1 = points[i][1];
      for (int j = i + 1; j < n; j++) {
        int x2 = points[j][0], y2 = points[j][1];
        if (x1 != x2 && y1 != y2) {
          if (m.count(((long long)x1 << 20) | y2) &&
              m.count(((long long)x2 << 20) | y1)) {
            ans = min(ans, abs(x1 - x2) * abs(y1 - y2));
          }
        }
      }
    }
    return ans == INT_MAX ? 0 : ans;
  }
};
