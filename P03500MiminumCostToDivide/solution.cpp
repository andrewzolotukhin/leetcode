class Solution {
private:
  long long divide(vector<long long> &prefixNums, vector<long long> &prefixCost,
                   int n, int k, int start, vector<long long> &memo) {
    if (start >= n) {
      return 0;
    }

    if (memo[start] != -1)
      return memo[start];

    long long ans = LLONG_MAX;
    int end = start;

    while (end < n) {
      long long pref = prefixNums[end];
      long long suffCost =
          prefixCost[n - 1] - (start > 0 ? prefixCost[start - 1] : 0);
      long long arrCost =
          prefixCost[end] - (start > 0 ? prefixCost[start - 1] : 0);
      long long cost = pref * arrCost + k * suffCost;
      ans =
          min(ans, cost + divide(prefixNums, prefixCost, n, k, end + 1, memo));
      end++;
    }
    memo[start] = ans;
    return ans;
  }

public:
  long long minimumCost(vector<int> &nums, vector<int> &cost, int k) {
    int n = nums.size();
    vector<long long> prefixNums(n, 0LL), prefixCost(n, 0LL);
    prefixNums[0] = nums[0];
    for (int i = 1; i < n; i++)
      prefixNums[i] = prefixNums[i - 1] + (long long)nums[i];
    prefixCost[0] = cost[0];
    for (int i = 1; i < n; i++)
      prefixCost[i] = prefixCost[i - 1] + (long long)cost[i];

    vector<long long> memo(1001, -1LL);

    long long ans = divide(prefixNums, prefixCost, n, k, 0, memo);

    return ans;
  }
};
