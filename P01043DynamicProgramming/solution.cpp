class Solution {
public:
  int maxSumAfterPartitioning(vector<int> &arr, int k) {
    int n = arr.size();
    vector<int> dp(n + 1, 0);

    for (int i = n - 1; i >= 0; i--) {
      int currM = 0;
      int end = min(n, i + k);

      for (int j = i; j < end; j++) {
        currM = max(currM, arr[j]);
        dp[i] = max(dp[i], dp[j + 1] + currM * (j - i + 1));
      }
    }

    return dp[0];
  }
};
