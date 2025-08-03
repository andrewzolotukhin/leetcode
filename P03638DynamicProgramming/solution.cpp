class Solution {
  int solve(vector<int> &weight, int start, unordered_map<int, int> &memo,
            int maxV) {
    if (memo.count(start))
      return memo[start];

    int n = weight.size();
    if (start >= n)
      return 0;
    int ans = 0;
    if (weight[start] < maxV) {
      // end
      ans = max(ans, 1 + solve(weight, start + 1, memo, 0));
    }

    // take
    ans = max(ans, solve(weight, start + 1, memo, max(weight[start], maxV)));

    return memo[start] = ans;
  }

public:
  int maxBalancedShipments(vector<int> &weight) {
    unordered_map<int, int> memo;
    return solve(weight, 0, memo, 0);
  }
};
