#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class Solution {
public:
  vector<int> queryResults(int limit, vector<vector<int>> &queries) {
    vector<int> result(queries.size());
    unordered_map<int, int> state;
    unordered_map<int, int> colors;

    int count = 0;

    for (int i = 0; i < queries.size(); i++) {
      if (queries[i][1] != state[queries[i][0]]) {
        if (state[queries[i][0]] != 0) {
          colors[state[queries[i][0]]]--;
          if (colors[state[queries[i][0]]] == 0) {
            count--;
          }
        }

        state[queries[i][0]] = queries[i][1];

        colors[state[queries[i][0]]]++;

        if (colors[state[queries[i][0]]] == 1) {
          count++;
        }
      }

      result[i] = count;
    }

    return result;
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  int limit, n;
  cin >> limit >> n;

  vector<vector<int>> queries(n, vector<int>(2));

  for (int i = 0; i < n; i++) {
    cin >> queries[i][0] >> queries[i][1];
  }

  auto result = Solution().queryResults(limit, queries);

  for (auto r : result) {
    cout << r << '\n';
  }
}
