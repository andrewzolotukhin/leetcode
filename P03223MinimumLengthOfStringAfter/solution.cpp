#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minimumLength(string s) {
    vector<int> freq(26, -2);
    for (int i = 0; i < s.size(); i++) {
      freq[s[i] - 'a']++;
    }

    int result = 0;
    for (int i = 0; i < 26; i++) {
      if (freq[i] > 0) {
        result += freq[i] & 1 ? (freq[i] + 1) : (freq[i]);
      }
    }

    return s.size() - result;
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  string s;
  cin >> s;

  Solution sol;

  cout << sol.minimumLength(s) << '\n';
}
