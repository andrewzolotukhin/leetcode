class Solution {
public:
  int maxFreeTime(int eventTime, int k, vector<int> &startTime,
                  vector<int> &endTime) {
    int n = startTime.size();

    vector<int> prefix(n + 1, 0);

    for (int i = 0; i < n; i++) {
      prefix[i + 1] = prefix[i] + endTime[i] - startTime[i];
    }

    int ans = 0;
    for (int i = k - 1; i < n; i++) {
      int r = (i == n - 1) ? eventTime : startTime[i + 1];
      int l = (i == k - 1) ? 0 : endTime[i - k];
      ans = max(ans, r - l - (prefix[i + 1] - prefix[i - k + 1]));
    }

    return ans;
  }
};
