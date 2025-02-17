#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool maxSubstringLength(string s, int k) {
    if (k == 0)
      return true;

    vector<vector<int>> indexes(26, vector<int>());

    for (int i = 0; i < s.size(); i++) {
      int index = s[i] - 'a';
      indexes[index].push_back(i);
    }

    int n = s.size();
    // next power of 2 greater or equal to n+1
    int treeSize = 1 << (int)ceil(log2(n + 1));
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  int k;
  string s;
  cin >> k >> s;

  cout << (Solution().maxSubstringLength(s, k) ? "yes" : "no") << '\n';
}
