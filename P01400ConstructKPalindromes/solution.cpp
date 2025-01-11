#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool canConstruct(string s, int k) {
    if (s.length() < k)
      return false;
    if (s.length() == k)
      return true;
    unsigned int bits = 0;
    for (int i = 0; i < s.size(); i++) {
      bits ^= (1 << (s[i] - 'a'));
    }

    int setBits = __builtin_popcount(bits);

    return setBits <= k;
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  int k;
  string s;

  cin >> k >> s;

  Solution sol;

  cout << (sol.canConstruct(s, k) ? "YES" : "NO") << '\n';
}
