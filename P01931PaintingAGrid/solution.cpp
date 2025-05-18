class Solution {
public:
  int colorTheGrid(int m, int n) {
    vector<vector<int>> possibles;
    int mod = (int)1e9 + 7;

    int total = 3;
    for (int i = 1; i < m; i++) {
      total *= 3;
    }

    for (int i = 0; i < total; i++) {
      int k = i;
      vector<int> cand = {i, k % 3};
      k /= 3;
      bool good = true;

      for (int j = 1; j < m; j++) {
        int next = k % 3;
        if (next == cand[j]) {
          good = false;
          break;
        }
        cand.push_back(next);
        k /= 3;
      }

      if (good) {
        possibles.push_back(cand);
      }
    }

    unordered_map<int, vector<int>> adj;

    for (int i = 0; i < possibles.size(); i++) {
      for (int j = 0; j < possibles.size(); j++) {
        // if(i==j) continue;
        bool good = true;
        for (int k = 1; k <= m; k++) {
          if (possibles[i][k] == possibles[j][k]) {
            good = false;
            break;
          }
        }
        if (good) {
          adj[possibles[i][0]].push_back(possibles[j][0]);
        }
      }
    }

    vector<int> dp(total);
    for (int i = 0; i < possibles.size(); i++) {
      dp[possibles[i][0]] = 1;
    }

    for (int i = 1; i < n; i++) {
      vector<int> res(total);
      for (int j = 0; j < possibles.size(); j++) {
        for (int k = 0; k < adj[possibles[j][0]].size(); k++) {
          res[possibles[j][0]] += dp[adj[possibles[j][0]][k]];
          if (res[possibles[j][0]] >= mod) {
            res[possibles[j][0]] -= mod;
          }
        }
      }
      dp = move(res);
    }

    int ans = 0;

    for (auto nn : dp) {
      ans += nn;
      if (ans >= mod) {
        ans -= mod;
      }
    }

    return ans;
  }
};
