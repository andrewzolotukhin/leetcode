#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maximalRectangle(vector<vector<char>> &matrix) {
    int N = matrix.size(), M = matrix[0].size();
    auto dp = vector<vector<pair<int, int>>>(N, vector<pair<int, int>>(M));
    auto dps = vector<vector<pair<int, int>>>(N, vector<pair<int, int>>(M));

    dp[0][0] = {(matrix[0][0] == '1' ? 1 : 0), (matrix[0][0] == '1' ? 1 : 0)};
    dps[0][0] = dp[0][0];

    int maxW = dps[0][0].second, maxH = dps[0][0].first;

    for (auto i = 1; i < N; i++) {
      dp[i][0] = {((matrix[i][0] == '0') ? 0 : 1),
                  ((matrix[i][0] == '0') ? 0 : (dp[i - 1][0].second + 1))};
      dps[i][0] = dp[i][0];
    }

    for (auto i = 1; i < M; i++) {
      dp[0][i] = {((matrix[0][i] == '0') ? 0 : 1),
                  ((matrix[0][i] == '0') ? 0 : (dp[0][i - 1].second + 1))};
      dps[0][i] = dp[0][i];
    }

    for (int i = 1; i < N; i++) {
      for (int j = 1; j < M; j++) {
        dp[i][j] = {
            (matrix[i][j] == '0') ? 0 : (dp[i - 1][j].first + 1),
            (matrix[i][j] == '0') ? 0 : (dp[i][j - 1].second + 1),
        };
      }
    }

    for (int i = 1; i < N; i++) {
      for (int j = 1; j < M; j++) {
        if (dp[i][j].first == 0 || dp[i][j].second == 0) {
          dps[i][j] = dp[i][j];
        } else {
          int w, h;
          auto maxAvW = dp[i][j].second;
          auto prevMaxW = dps[i - 1][j - 1].second;
          auto maxAvH = dp[i][j].first;
          auto prevMaxH = dps[i - 1][j - 1].first;

          w = max(min(prevMaxW + 1, maxAvW), 1);
          h = max(min(prevMaxH + 1, maxAvH), 1);

          if (w * h > maxAvW && w * h > maxAvH) {
            dps[i][j] = {w, h};
          } else {
            if (maxAvW > maxAvH) {
              dps[i][j] = {1, maxAvW};
            } else {
              dps[i][j] = {maxAvH, 1};
            }
          }
        }

        if (dps[i][j].first * dps[i][j].second > maxW * maxH) {
          maxH = dps[i][j].first;
          maxW = dps[i][j].second;
        }
      }
    }

    cout << "DPw:\n";
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        cout << dp[i][j].second << " ";
      }
      cout << '\n';
    }
    cout << "DPh:\n";
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        cout << dp[i][j].first << " ";
      }
      cout << '\n';
    }

    cout << "DPsw:\n";
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        cout << dps[i][j].second << " ";
      }
      cout << '\n';
    }

    cout << "DPsh:\n";
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        cout << dps[i][j].first << " ";
      }
      cout << '\n';
    }

    return maxW * maxH;
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  Solution sol;

  int n;

  cin >> n;

  vector<vector<char>> m;

  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    vector<char> v;
    for (char c : s) {
      v.push_back(c);
    }
    m.push_back(v);
  }

  cout << sol.maximalRectangle(m) << '\n';
}
