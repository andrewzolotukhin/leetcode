#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  vector<vector<int>> C = {{1, 0, 0, 0, 0, 0}, {1, 1, 0, 0, 0, 0},
                           {1, 2, 1, 0, 0, 0}, {1, 3, 3, 1, 0, 0},
                           {1, 4, 6, 4, 1, 0}, {1, 5, 10, 10, 5, 1}};
  int cmod(int n, int k, int p) {
    int ans = 1;
    while (n > 0 || k > 0) {
      if (ans == 0)
        return 0;
      int a = n % p;
      int b = k % p;
      n /= p;
      k /= p;
      ans *= (C[a][b] % p);
    }

    return ans % p;
  }

public:
  bool hasSameDigits(string s) {
    // 0: (d1)(d2)(d3)(d4)(d5)(d6)
    // 1: (d1+d2)(d2+d3)(d3+d4)(d4+d5)(d5+d6) - C(1, ...)
    // 2: (d1 + 2*d2 + d3)(d2 + 2*d3 + d4)(d3 + 2*d4 + d5)(d4 + 2*d5 + d6) -
    // C(2, ...)
    // 3: (d1 + 3*d2 + 3*d3 + d4)(d2 + 3*d3 + 3*d4 + d5)(d3 + 3*d4 +
    // 3*d5 + d6) - C(3, ...)
    // 4: (d1 + 4*d2 + 6*d3 + 4*d4 + d5)(d2 + 4*d3 + 6*d4 + 4*d5 + d6) - C(n -
    // 2, 0..n-2)

    vector<int> cmod10;

    int n = s.size();

    for (int i = 0; i <= n - 2; i++) {
      int mod2 = cmod(n - 2, i, 2);
      int mod5 = cmod(n - 2, i, 5);
      int mod10 = (5 * mod2 + 6 * mod5) % 10;
      cmod10.push_back(mod10);
    }

    int s1 = 0;
    int s2 = 0;
    for (int i = 0; i < n; i++) {
      auto v = s[i] - '0';
      if (v == 0)
        continue;
      if (i < n - 1) {
        s1 += v * cmod10[i];
        s1 %= 10;
      }
      if (i > 0) {
        s2 += v * cmod10[i - 1];
        s2 %= 10;
      }
    }

    return s1 == s2;
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  string s;
  cin >> s;

  cout << (Solution().hasSameDigits(s) ? "YES\n" : "NO\n") << endl;
}
