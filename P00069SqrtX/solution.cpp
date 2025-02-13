#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int mySqrt(int x) {
    long left = 1, right = x;
    long current = 0;
    if (x <= 1)
      return x;

    while (left < right) {
      long mid = left + (right - left) / 2;
      if (mid == left)
        return left;

      if (mid * mid == x) {
        return mid;
      }

      if (mid * mid >= x) {
        right = mid;
      } else {
        left = mid;
      }
    }

    assert(false);
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  int n;
  cin >> n;
  cout << Solution().mySqrt(n) << '\n';
}
