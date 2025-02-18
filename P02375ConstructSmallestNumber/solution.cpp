#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  bool solve(int index, string &pattern, vector<bool> &used, string &result) {
    int n = pattern.size();

    if (index >= n)
      return true;

    int prevVal = result[index] - '0';

    if (pattern[index] == 'I') {
      for (int i = prevVal + 1; i <= 9; i++) {
        if (used[i])
          continue;
        used[i] = true;
        result[index + 1] = i + '0';
        if (solve(index + 1, pattern, used, result)) {
          return true;
        }
        used[i] = false;
      }
    } else {
      if (prevVal == 1)
        return false;
      for (int i = 1; i <= prevVal - 1; i++) {
        if (used[i])
          continue;
        used[i] = true;
        result[index + 1] = i + '0';
        if (solve(index + 1, pattern, used, result)) {
          return true;
        }
        used[i] = false;
      }
    }

    return false;
  }

public:
  string smallestNumber(string pattern) {
    int n = pattern.size();
    for (int i = 0; i < 9; i++) {
      string result(n + 1, i + '1');
      vector<bool> used(10, false);
      used[i + 1] = true;
      if (solve(0, pattern, used, result)) {
        return result;
      }
      used[i + 1] = false;
    }

    assert(false);
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  string pattern;
  cin >> pattern;

  cout << Solution().smallestNumber(pattern) << '\n';
}
