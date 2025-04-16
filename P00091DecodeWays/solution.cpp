class Solution {
public:
  int numDecodings(string s) {
    int n = s.size();
    vector<int> dp(n + 2, 1);
    if (s[0] == '0')
      return 0;
    for (int i = n - 1; i >= 0; i--) {
      if (i < n - 1 && (s[i + 1] == '0' && s[i] > '2'))
        return 0;
      dp[i] =
          s[i] == '0'
              ? 0
              : dp[i + 1] + ((i < n - 1 &&
                              (s[i] == '1' || (s[i] == '2' && s[i + 1] < '7')))
                                 ? dp[i + 2]
                                 : 0);
    }

    return dp[0];
  }
};
