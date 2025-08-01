class Solution {
public:
  int atMostNGivenDigitSet(vector<string> &digits, int n) {
    string s = to_string(n);
    int sSize = s.size();

    vector<int> dp(sSize + 1, 0);
    dp[sSize] = 1;

    for (int i = sSize - 1; i >= 0; i--) {
      auto c = s[i];
      for (auto d : digits) {
        if (d[0] < c) {
          dp[i] += pow(digits.size(), sSize - i - 1);
        } else if (d[0] == c) {
          dp[i] += dp[i + 1];
        }
      }
    }

    for (int i = 1; i < sSize; i++) {
      dp[0] += pow(digits.size(), i);
    }

    return dp[0];
  }
};
