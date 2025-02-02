#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxDistance(string s, int k) {
    int n = s.size();

    int x = 0, y = 0;

    int m = INT_MIN;

    for (int i = 0; i < n; i++) {
      if (s[i] == 'S') {
        x--;
      } else if (s[i] == 'N') {
        x++;
      } else if (s[i] == 'W') {
        y--;
      } else {
        y++;
      }

      int currentMaxDistance = i + 1;
      int distance = abs(x) + abs(y);

      int maxChanges = min(k, currentMaxDistance);

      int candidate =
          min(currentMaxDistance, max(distance, distance + maxChanges * 2));

      m = max(m, candidate);
    }

    return m;
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  int k;
  cin >> k;
  string s;
  cin >> s;

  cout << Solution().maxDistance(s, k) << '\n';
}
