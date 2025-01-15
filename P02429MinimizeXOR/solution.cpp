#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minimizeXor(int num1, int num2) {
    int pc1 = __builtin_popcount(num1);
    int pc2 = __builtin_popcount(num2);
    if (pc2 == pc1) {
      return num1;
    }
    if (pc1 > pc2) {
      int res = num1;
      int k = 0;
      int r = 1;
      for (int i = 0; i <= 31 && k < (pc1 - pc2); i++) {
        if (res & r) {
          res -= r;
          k++;
        }
        r *= 2;
      }
      return res;
    }

    int res = num1;
    int remaining = pc2 - pc1;
    int i = 1;
    while (remaining > 0 && i <= (1 << 30)) {
      if ((res & i) == 0) {
        res |= i;
        remaining--;
      }
      i *= 2;
    }

    return res;
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int num1, num2;
  cin >> num1 >> num2;

  Solution s;

  cout << s.minimizeXor(num1, num2) << '\n';
}
