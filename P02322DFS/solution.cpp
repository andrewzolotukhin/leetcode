class Solution {
private:
  int calc(int a, int b, int c) {
    return max(a, max(b, c)) - min(a, min(b, c));
  }

public:
  int minimumScore(vector<int> &nums, vector<vector<int>> &edges) {
    int n = nums.size();
    vector<vector<int>> adj(n);
    for (auto &e : edges) {
      adj[e[0]].push_back(e[1]);
      adj[e[1]].push_back(e[0]);
    }

    int totalXor = 0;
    for (auto v : nums)
      totalXor ^= v;

    int ans = INT_MAX;

    function<int(int, int, int, int)> dfs2 = [&](int a, int b, int c, int d) {
      int s = nums[a];
      for (auto &v : adj[a]) {
        if (v == b)
          continue;
        s ^= dfs2(v, a, c, d);
      }
      if (b == d)
        return s;

      ans = min(ans, calc(c, s, totalXor ^ c ^ s));
      return s;
    };

    function<int(int, int)> dfs = [&](int a, int b) {
      int s = nums[a];
      for (auto &v : adj[a]) {
        if (v == b)
          continue;
        s ^= dfs(v, a);
      }

      for (auto &v : adj[a]) {
        if (v == b) {
          dfs2(b, a, s, a);
        }
      }

      return s;
    };

    dfs(0, -1);
    return ans;
  }
};
