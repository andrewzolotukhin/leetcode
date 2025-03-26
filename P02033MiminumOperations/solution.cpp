class Solution {
public:
  int minOperations(vector<vector<int>> &grid, int x) {
    int n = grid.size();
    int m = grid[0].size();

    vector<int> arr;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if ((grid[i][j] % x) != (grid[0][0] % x))
          return -1;
        arr.push_back(grid[i][j]);
      }
    }

    sort(arr.begin(), arr.end());

    vector<int> prefix(arr.size() + 1, 0);
    for (int i = 0; i < arr.size(); i++) {
      prefix[i + 1] = prefix[i] + arr[i];
    }

    int ans = INT_MAX;
    for (int i = 0; i < arr.size(); i++) {
      if (i > 0 && arr[i] == arr[i - 1])
        continue;

      int l = (arr[i] * i - prefix[i]) / x;
      int r =
          (prefix[arr.size()] - prefix[i + 1] - arr[i] * (arr.size() - i - 1)) /
          x;
      ans = min(ans, l + r);
    }

    return ans;
  }
};
