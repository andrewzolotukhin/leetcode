#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxDifference(string s) {
    unordered_map<char, int> freq;

    for (auto c : s) {
      freq[c]++;
    }

    int max = INT_MIN;

    for (auto [c, f] : freq) {
      for (auto [c2, f2] : freq) {
        if (c == c2) {
          continue;
        }

        if (f % 2 != 1) {
          continue;
        }
        if (f2 % 2 != 0) {
          continue;
        }

        int res = f - f2;
        if (res > max) {
          max = res;
        }
      }
    }

    return max;
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  string s;
  cin >> s;

  cout << Solution().maxDifference(s) << '\n';
}
