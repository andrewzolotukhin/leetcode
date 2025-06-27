class Solution {
private:
  int solve(vector<int> &cost, int p, unordered_map<int, int> &memo) {
    if (p >= cost.size())
      return 0;
    if (memo.count(p))
      return memo[p];

    return memo[p] = cost[p] +
                     min(solve(cost, p + 1, memo), solve(cost, p + 2, memo));
  }

public:
  int minCostClimbingStairs(vector<int> &cost) {
    unordered_map<int, int> memo;
    return min(solve(cost, 0, memo), solve(cost, 1, memo));
  }
};
