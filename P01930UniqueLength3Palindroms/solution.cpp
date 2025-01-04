#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

int solve(string s) {
  int n = s.size();
  auto counts = vector<vector<int>>(n + 1, vector<int>(26, 0));
  auto indexes = vector<pair<int, int>>(26, {-1, -1});
  int result = 0;
  for (int i = 1; i <= n; i++) {
    int c = (int)(s[i - 1] - 'a');
    for (int j = 0; j < 26; j++) {
      counts[i][j] = counts[i - 1][j] + ((j == c) ? 1 : 0);
    }
    if (indexes[c].first == -1) {
      indexes[c] = {i, i};
    } else {
      indexes[c].second = i;
    }
  }
  for (int i = 0; i < 26; i++) {
    if (indexes[i].second - indexes[i].first < 2) {
      continue;
    }
    for (int j = 0; j < 26; j++) {
      result +=
          ((counts[indexes[i].second - 1][j] - counts[indexes[i].first][j]) > 0)
              ? 1
              : 0;
    }
  }
  return result;
}

int main() {
  string s;
  int n;
  cin >> n;
  while (n--) {
    cin >> s;
    cout << solve(s) << '\n';
  }
}
