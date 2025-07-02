class Solution {
private:
  int solve(vector<int> &row) {
    int n = row.size();
    if (row[0] < 0)
      return n;
    if (row[n - 1] >= 0)
      return 0;

    int l = 0, r = n - 1;

    while (l < r) {
      int mid = l + (r - l) / 2;

      if (row[mid] >= 0) {
        l = mid + 1;
      } else {
        r = mid;
      }
    }
    return n - l;
  }

public:
  int countNegatives(vector<vector<int>> &grid) {
    int ans = 0;
    for (auto r : grid)
      ans += solve(r);
    return ans;
  }
};
