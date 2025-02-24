#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool hasSameDigits(string s) {
    int n = s.size();
    vector<int> d(n);
    for (int i = 0; i < n; i++) {
      d[i] = s[i] - '0';
    }

    int steps = n - 2;
    if (steps == 0)
      return d[0] == d[1];

    vector<int> coef(steps + 1);
    coef[0] = 1;
    for (int i = 1; i <= steps; i++) {
      coef[i] = (coef[i - 1] * (steps - (i - 1)) + i - 1) / i; // Fix division
    }

    int d0 = 0, d1 = 0;
    for (int i = 0; i < n; i++) {
      if (i <= steps)
        d0 = (d0 + d[i] * (coef[i] % 10)) % 10;
      if (i > 0 && i - 1 <= steps)
        d1 = (d1 + d[i] * (coef[i - 1] % 10)) % 10;
    }

    return d0 == d1;
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  string s;
  cin >> s;

  cout << (Solution().hasSameDigits(s) ? "YES\n" : "NO\n") << endl;
}
