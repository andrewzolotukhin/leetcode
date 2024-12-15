#include <bits/stdc++.h>
#include <climits>
using namespace std;

class Solution {
public:
  double myPow(double x, int n) {
    double res = 1.0;

    if (n < 0) {
      if (n > INT_MIN) {
        return 1 / myPow(x, -n);
      }
      return 1 / myPow(x, -(n + 1)) / x;
    }

    while (n > 0) {
      if (n & 1) {
        res *= x;
      }

      x *= x;
      n >>= 1;
    }

    return res;
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  Solution s;

  double x;
  int n;

  cin >> x >> n;

  cout << s.myPow(x, n) << '\n';
}
