class Solution {
public:
  int minimumDeletions(string s) {
    int n = s.size();
    int cb = 0;
    int ans = 0;

    for (int i = 0; i < n; i++) {
      if (s[i] == 'b') {
        cb++;
      } else {
        ans = min(ans + 1, cb);
      }
    }

    return ans;
  }
};
