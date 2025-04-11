class Solution {
public:
  int minimumDeletions(string s) {
    int n = s.size();
    vector<int> counta(n, 0);
    vector<int> countb(n, 0);
    int ca = 0;
    int cb = 0;

    for (int i = 0; i < n; i++) {
      countb[i] = cb;
      if (s[i] == 'b')
        cb++;
    }

    for (int i = n - 1; i >= 0; i--) {
      counta[i] = ca;
      if (s[i] == 'a')
        ca++;
    }

    int ans = INT_MAX;

    for (int i = 0; i < n; i++) {
      ans = min(ans, counta[i] + countb[i]);
    }

    return ans;
  }
};
