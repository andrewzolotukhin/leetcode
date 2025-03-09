#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int numberOfAlternatingGroups(vector<int> &colors, int k) {
    int result = 0, l = 0, r = 0, n = colors.size();
    vector<bool> visited(n, false);

    visited[0] = true;

    int count = 1;

    while (1) {
      int nextR = (n + r - 1) % n;
      if (visited[nextR] || colors[nextR] == colors[r]) {
        break;
      }
      count++;
      r = nextR;
      visited[r] = true;
    }

    if (count == n && n > 1 && colors[0] != colors[1]) {
      result = n;
      count = 0;
    }

    while (1) {
      int nextL = (l + 1) % n;
      if (visited[nextL] || colors[nextL] == colors[l]) {
        if (count >= k) {
          result += count - k + 1;
        }
        l = nextL;
        count = 1;
        if (visited[nextL]) {
          break;
        }
        continue;
      }
      count++;
      l = nextL;
      visited[l] = true;
    }

    return result;
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  int n, k;

  cin >> n >> k;

  vector<int> colors(n);

  while (n--) {
    cin >> colors[n];
  }

  cout << Solution().numberOfAlternatingGroups(colors, k) << endl;
}
