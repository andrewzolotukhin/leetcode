class Solution {
private:
  int dfs(int curr, int k, vector<vector<int>> &events,
          vector<vector<int>> &dp) {
    int n = events.size();
    if (k == 0 || curr > n - 1) {
      return 0;
    }

    if (dp[curr][k] != -1)
      return dp[curr][k];

    int l = 0, r = n;
    while (l < r) {
      int mid = (l + r) / 2;
      if (events[mid][0] <= events[curr][1]) {
        l = mid + 1;
      } else {
        r = mid;
      }
    }

    return dp[curr][k] = max(dfs(curr + 1, k, events, dp),
                             events[curr][2] + dfs(l, k - 1, events, dp));
  }

public:
  int maxValue(vector<vector<int>> &events, int k) {
    sort(events.begin(), events.end());
    int n = events.size();
    vector<vector<int>> dp = vector<vector<int>>(n, vector<int>(k + 1, -1));
    return dfs(0, k, events, dp);
  }
};
