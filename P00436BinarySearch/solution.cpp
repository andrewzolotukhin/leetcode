class Solution {
public:
  vector<int> findRightInterval(vector<vector<int>> &intervals) {
    int n = intervals.size();
    vector<int> ans(n, -1);
    for (int i = 0; i < n; i++)
      intervals[i].push_back(i);

    sort(intervals.begin(), intervals.end());

    for (int i = 0; i < n; i++) {
      int l = i, r = n - 1;
      if (intervals[n - 1][0] < intervals[i][1]) {
        continue;
      }
      while (l < r) {
        int mid = l + (r - l) / 2;

        if (intervals[mid][0] < intervals[i][1]) {
          l = mid + 1;
        } else {
          r = mid;
        }
      }
      if (intervals[l][0] >= intervals[i][1]) {
        ans[intervals[i][2]] = intervals[l][2];
      }
    }

    return ans;
  }
};
