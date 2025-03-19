#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool hasSameDigits(string s) {
    vector<int> init;

    for (int i = 0; i < s.size(); i++) {
      init.push_back(s[i] - '0');
    }

    while (init.size() > 2) {
      for (int i = 0; i < init.size() - 1; i++) {
        init[i] = (init[i] + init[i + 1]) % 10;
      }
      init.pop_back();
    }

    return init[0] == init[1];
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  string s;
  cin >> s;

  cout << (Solution().hasSameDigits(s) ? "YES\n" : "NO\n") << endl;
}
