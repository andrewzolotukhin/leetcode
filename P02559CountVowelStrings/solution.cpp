#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> vowelStrings(vector<string> &words,
                           vector<vector<int>> &queries) {
    auto isVovel = [&](char c) {
      return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    };

    int n = words.size();
    vector<int> v(n + 1, 0);
    for (int i = 1; i <= n; i++) {
      v[i] = v[i - 1] + ((isVovel(words[i - 1][0]) &&
                          isVovel(words[i - 1][words[i - 1].size() - 1]))
                             ? 1
                             : 0);
    }
    vector<int> result;

    for (int i = 0; i < queries.size(); i++) {
      result.push_back(v[queries[i][1] + 1] - v[queries[i][0]]);
    }
    return result;
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  int n;
  cin >> n;
  vector<string> words(n);
  for (int i = 0; i < n; i++) {
    cin >> words[i];
  }

  int m;
  cin >> m;
  vector<vector<int>> queries(m, vector<int>(2));
  for (int i = 0; i < m; i++) {
    cin >> queries[i][0] >> queries[i][1];
  }

  Solution sol;

  auto result = sol.vowelStrings(words, queries);

  for (auto res : result) {
    cout << res << '\n';
  }
}
