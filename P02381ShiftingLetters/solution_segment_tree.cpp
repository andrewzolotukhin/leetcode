#include <bits/stdc++.h>
#include <climits>
using namespace std;

class Solution {
public:
  void update(vector<int> &tree, int current, int currentLow, int currentHigh,
              int segmentStart, int segmentEnd, int diff) {
    if (segmentStart > currentHigh || segmentEnd < currentLow) {
      return;
    }

    auto empty = tree[current] == INT_MIN;

    if (empty) {
      tree[current] = diff;

      if (segmentStart == currentLow && segmentEnd == currentHigh) {
        return;
      }

      if (currentHigh - currentLow < 2)
        return;

      update(tree, current * 2, currentLow, (currentLow + currentHigh) / 2,
             segmentStart, segmentEnd, diff);
      update(tree, current * 2 + 1, (currentLow + currentHigh) / 2 + 1,
             currentHigh, segmentStart, segmentEnd, diff);
    } else {
      if (currentHigh - currentLow >= 2 && tree[current * 2] != INT_MIN &&
          tree[current * 2 + 1] != INT_MIN && segmentStart == currentLow &&
          segmentEnd == currentHigh) {
        tree[current] += diff;
        return;
      }

      if (currentHigh - currentLow < 2) {
        tree[current] += diff;
        return;
      }

      update(tree, current * 2, currentLow, (currentLow + currentHigh) / 2,
             segmentStart, segmentEnd, diff);

      update(tree, current * 2 + 1, (currentLow + currentHigh) / 2 + 1,
             currentHigh, segmentStart, segmentEnd, diff);
    }
  }

  string compile(string &source, string &result, vector<int> &tree, int current,
                 int currentLow, int currentHigh) {
    if (currentHigh - currentLow < 2) {
      result[current - tree.size() / 2] =
          (source[current - tree.size() / 2] + tree[current] + 26) % 26;
    }

    if (tree[current * 2] == INT_MIN && tree[current * 2 + 1] == INT_MIN) {
      for (int i = currentLow; i <= currentHigh; i++) {
        // !!!!!!!!!!!!!!!
      }
    }
  }

  string shiftingLetters(string s, vector<vector<int>> &shifts) {

    int n = shifts.size();
    int nextPow2 = 1;
    while (nextPow2 < shifts.size())
      nextPow2 <<= 1;

    vector<int> tree = vector<int>(nextPow2, INT_MIN);

    for (int i = 0; i < shifts.size(); i++) {
      update(tree, 0, 0, n, shifts[i][0], shifts[i][1],
             ((shifts[i][2] == 1) ? 1 : -1));
    }

    string result(s);
    return compile(s, result, tree, 0, 0, n);
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  int n;
  string s;
  cin >> s;
  cin >> n;

  vector<vector<int>> shifts(n);

  for (int i = 0; i < n; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    shifts.push_back({
        a,
        b,
        c,
    });
  }

  Solution sol;
  cout << sol.shiftingLetters(s, shifts) << '\n';
}
