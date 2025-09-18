class Solution {
public:
  int maxSatisfaction(vector<int> &s) {
    sort(s.begin(), s.end());
    int n = s.size();
    int ans = 0;
    for (int i = 0; i < n; i++) {
      int c = 0;
      for (int j = i; j < n; j++) {
        c += s[j] * (j - i + 1);
      }
      if (c > ans)
        ans = c;
    }
    return ans;
  }
};
