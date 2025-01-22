#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxScore(string s) {
    int n = s.size();
    vector<int> zeros(n + 1, 0), ones(n + 1, 0);
    for (int i = 0; i < n; i++) {
      zeros[i + 1] = zeros[i] + (s[i] == '0');
    }

    for (int j = n - 1; j >= 0; j--) {
      ones[j] = ones[j + 1] + (s[j] == '1');
    }

    int max = 0;
    for (int i = 1; i < n; i++) {
      int score = zeros[i] + ones[i];
      if (score > max) {
        max = score;
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

  Solution sol;

  cout << sol.maxScore(s) << '\n';
}
