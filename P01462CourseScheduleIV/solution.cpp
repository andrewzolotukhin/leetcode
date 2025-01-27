#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  void dfs(int u, vector<vector<bool>> &adj, vector<vector<bool>> &dp) {
    dp[u][u] = true;
    for (int v = 0; v < adj.size(); v++) {
      if (adj[u][v] && !dp[u][v]) {
        dfs(v, adj, dp);
        for (int i = 0; i < adj.size(); i++) {
          dp[u][i] = dp[u][i] || dp[v][i];
        }
      }
    }
  }

public:
  vector<bool> checkIfPrerequisite(int numCourses,
                                   vector<vector<int>> &prerequisites,
                                   vector<vector<int>> &queries) {
    int m = prerequisites.size();
    int q = queries.size();

    vector<vector<bool>> adj(numCourses, vector<bool>(numCourses, false));
    vector<vector<bool>> dp(numCourses, vector<bool>(numCourses, false));

    for (int i = 0; i < m; i++) {
      adj[prerequisites[i][0]][prerequisites[i][1]] = true;
    }

    for (int i = 0; i < numCourses; i++) {
      dfs(i, adj, dp);
    }

    vector<bool> res(q);

    for (int i = 0; i < q; i++) {
      res[i] = dp[queries[i][0]][queries[i][1]];
    }

    return res;
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  int n, m, q;
  cin >> n >> m >> q;

  vector<vector<int>> prerequisites(m, vector<int>(2, 0));
  vector<vector<int>> queries(q, vector<int>(2, 0));

  for (int i = 0; i < m; i++) {
    cin >> prerequisites[i][0] >> prerequisites[i][1];
  }

  for (int i = 0; i < q; i++) {
    cin >> queries[i][0] >> queries[i][1];
  }

  auto res = Solution().checkIfPrerequisite(n, prerequisites, queries);

  for (auto x : res) {
    cout << (x ? "YES" : "NO") << '\n';
  }
}
