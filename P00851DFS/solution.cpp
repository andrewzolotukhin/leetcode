class Solution {
private:
  inline int dfs(unordered_map<int, int> &memo, vector<vector<int>> &adj,
                 vector<int> &quiet, int idx, int mv) {
    if (memo.count(idx))
      return memo[idx];
    int minI = idx;
    if (mv > quiet[idx])
      mv = quiet[idx];
    int n = quiet.size();
    for (int i = 0; i < adj[idx].size(); i++) {
      int r = dfs(memo, adj, quiet, adj[idx][i], mv);
      if (quiet[r] < mv) {
        mv = quiet[r];
        minI = r;
      }
    }
    return memo[idx] = minI;
  }

public:
  vector<int> loudAndRich(vector<vector<int>> &richer, vector<int> &quiet) {
    int n = quiet.size();
    unordered_map<int, int> memo;
    vector<vector<int>> adj(n);
    for (auto &r : richer)
      adj[r[1]].push_back(r[0]);

    vector<int> ans;
    for (int i = 0; i < n; i++)
      ans.push_back(dfs(memo, adj, quiet, i, quiet[i]));

    return ans;
  }
};
