#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int countGoodStrings(int low, int high, int zero, int one) {
    auto divider = 1000000007;
    auto cache = vector<int>(high + 1, 0);

    cache[0] = 1;

    int result = 0;

    for (int i = 1; i <= high; i++) {
      if (i >= zero) {
        cache[i] += cache[i - zero] % divider;
      }
      if (i >= one) {
        cache[i] += cache[i - one] % divider;
      }
    }

    for (int i = low; i <= high; i++) {
      result += cache[i] % divider;
      result = result % divider;
    }

    return (result + divider) % divider;
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  int low, high, zero, one;

  cin >> low >> high >> zero >> one;

  Solution s;

  cout << s.countGoodStrings(low, high, zero, one) << '\n';
}
