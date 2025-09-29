class Solution {
private:
  int solve(vector<int> &values, int start, int end,
            unordered_map<int, int> &memo) {
    int key = start * 100 + end;
    if (memo.count(key))
      return memo[key];
    int ans = 0;
    for (int i = start + 1; i < end; i++) {
      ans = min(ans == 0 ? INT_MAX : ans,
                solve(values, start, i, memo) +
                    values[start] * values[i] * values[end] +
                    solve(values, i, end, memo));
    }
    return memo[key] = ans;
  }

public:
  int minScoreTriangulation(vector<int> &values) {
    unordered_map<int, int> memo;
    return solve(values, 0, values.size() - 1, memo);
  }
};
