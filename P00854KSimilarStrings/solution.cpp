class Solution {
private:
  void solve(string &s1, string &s2, int &ans, int curr, int idx) {
    int n = s1.size();
    if (curr > ans)
      return;
    for (int i = idx; i < n; i++) {
      if (s1[i] == s2[i])
        continue;
      if (curr + 1 >= ans)
        return;
      for (int j = i + 1; j < n; j++) {
        if (s1[j] == s2[i]) {
          auto t = s1[i];
          s1[i] = s1[j];
          s1[j] = t;
          if (s1 == s2) {
            ans = (ans > curr + 1) ? curr + 1 : ans;
            s1[i] = s1[j];
            s1[j] = s2[i];
          } else {
            if (curr + 1 < ans) {
              solve(s1, s2, ans, curr + 1, i);
            }
            s1[i] = s1[j];
            s1[j] = s2[i];
          }
        }
      }
      break;
    }
  }

public:
  int kSimilarity(string s1, string s2) {
    int n = s1.size();

    int ans = INT_MAX;
    if (s1 == s2)
      return 0;

    solve(s1, s2, ans, 0, 0);
    return ans;
  }
};
