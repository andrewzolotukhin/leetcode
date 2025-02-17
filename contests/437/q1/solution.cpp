#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool hasSpecialSubstring(string s, int k) {
    int cs = 1;
    char prev = s[0];

    for (int i = 1; i < s.size(); i++) {
      if (s[i] == prev) {
        cs++;
      } else {
        if (cs == k) {
          return true;
        }

        cs = 1;
        prev = s[i];
      }
    }

    return (cs == k);
  }
};

int main() {

  int k;
  string s;

  cin >> k >> s;

  cout << (Solution().hasSpecialSubstring(s, k) ? "yes" : "no") << endl;
}
