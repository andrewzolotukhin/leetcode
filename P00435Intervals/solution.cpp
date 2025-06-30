class Solution {
public:
  int eraseOverlapIntervals(vector<vector<int>> &intervals) {
    auto comp = [&](vector<int> &a, vector<int> &b) {
      if (a[0] == b[0]) {
        return a[1] < b[1];
      }
      return a[0] < b[0];
    };

    sort(intervals.begin(), intervals.end());

    int n = intervals.size();

    int ans = 0;
    auto last = intervals[0];

    for (int i = 1; i < n; i++) {
      if (intervals[i][0] < last[1]) {
        last[1] = min(last[1], intervals[i][1]);
        ans++;
      } else {
        last = intervals[i];
      }
    }

    return ans;
  }
};
