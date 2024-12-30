#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int numWays(vector<string> &words, string target) {
    int n = words.size();
    if (n < 1)
      return 0;

    int m = words[0].size();

    vector<vector<vector<vector<int>>>> cache(
        n,
        vector<vector<vector<int>>>(m, vector<vector<int>>(26, vector<int>())));

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        int l = (int)(words[i][j] - 'a');
        for (int k = 0; k < 26; k++) {
          if (j > 0) {
            cache[i][j][k] = cache[i][j - 1][k];
          }
          if (l == k) {
            cache[i][j][k].push_back(j);
          }
        }
      }
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        for (int k = 0; k < 26; k++) {
          if (cache[i][j][k].size()) {
            cout << words[i] << " -> index " << j << " -> char "
                 << ((char)(k + 'a')) << ": " << cache[i][j][k].size() << '\n';
          }
        }
      }
    }

    return getNum(target, target.size() - 1, m - 1, cache);
  }

  int getNum(string s, int k, int m,
             vector<vector<vector<vector<int>>>> &freq) {
    int divider = 1000000007;
    if (k < 0 || m <= 0)
      return 0;

    int result = 0;
    int l = (int)(s[k] - 'a');
    if (k == 0) {
      for (int i = 0; i < freq.size(); i++) {
        result += freq[i][m][l].size();
      }
    } else {
      for (int i = 0; i < freq.size(); i++) {
        // for (int j = 0; j < freq[i][m][l].size(); j++) {
        if (freq[i][m][l].size()) {
          result +=
              getNum(s, k - 1, freq[i][m][l][freq[i][m][l].size() - 1], freq) %
              divider;
        }
        // }
      }
    }
    return result % divider;
  }
};

int main() {
  // cin.tie(0)->sync_with_stdio(0);
  // cin.exceptions(cin.failbit);

  int n;
  cin >> n;
  vector<string> strs;

  string target;

  cin >> target;

  while (n--) {
    string s;
    cin >> s;
    strs.push_back(s);
  }

  Solution sol;

  cout << sol.numWays(strs, target) << endl;
}
