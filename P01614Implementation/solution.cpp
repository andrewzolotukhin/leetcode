class Solution {
public:
  int maxDepth(string s) {
    int d = 0;
    int ans = 0;
    for (auto c : s) {
      if (c == '(') {
        ans = max(ans, ++d);
      }
      if (c == ')')
        d--;
    }

    return ans;
  }
};
