class Solution {
public:
  int maxFreeTime(int eventTime, vector<int> &startTime, vector<int> &endTime) {
    int n = startTime.size();
    int ans = 0;

    vector<bool> memo(n);

    for (int i = 0, t1 = 0, t2 = 0; i < n; i++) {
      if (endTime[i] - startTime[i] <= t1) {
        memo[i] = true;
      }
      t1 = max(t1, startTime[i] - (i == 0 ? 0 : endTime[i - 1]));

      if (endTime[n - i - 1] - startTime[n - i - 1] <= t2) {
        memo[n - i - 1] = true;
      }
      t2 =
          max(t2, (i == 0 ? eventTime : startTime[n - i]) - endTime[n - i - 1]);
    }

    for (int i = 0; i < n; i++) {
      int l = (i == 0) ? 0 : endTime[i - 1];
      int r = (i == n - 1) ? eventTime : startTime[i + 1];

      if (memo[i]) {
        ans = max(ans, r - l);
      } else {
        ans = max(ans, r - l - (endTime[i] - startTime[i]));
      }
    }

    return ans;
  }
};
