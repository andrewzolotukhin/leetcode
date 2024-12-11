#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void permute(vector<char> &current, vector<char> &next, int *result,
               vector<bool> &d1, vector<bool> &d2) {
    if (next.size() == 0) {
      (*result)++;
      return;
    }

    for (int i = 0; i < next.size(); i++) {
      auto dx = next[i] - current.size();
      auto dy = next[i] + current.size();

      if (d1[100 + dx] || d2[100 + dy]) {
        continue;
      }

      if (current.size() > 0 &&
          abs(current[current.size() - 1] - next[i]) <= 1) {
        continue;
      }

      d1[100 + dx] = true;
      d2[100 + dy] = true;

      current.push_back(next[i]);
      next.erase(next.begin() + i);

      permute(current, next, result, d1, d2);

      next.insert(next.begin() + i, current.at(current.size() - 1));
      current.pop_back();
      d1[100 + dx] = false;
      d2[100 + dy] = false;
    }
  }

  int totalNQueens(int n) {
    vector<char> next;
    int result = 0;
    for (char i = 0; i < n; i++) {
      next.push_back(i);
    }

    vector<char> perms;
    vector<bool> d1 = vector<bool>(200, false);
    vector<bool> d2 = vector<bool>(200, false);

    permute(perms, next, &result, d1, d2);

    return result;
  }
};

void solve() {}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  auto solution = Solution();

  for (auto i = 1; i <= 25; i++) {
    cout << i << " - " << solution.totalNQueens(i) << endl;
  }

  solve();
}
