class Solution {
public:
  int memo[20];
  int solve(int n) {
    if (memo[n])
      return memo[n];

    for (int i = 0; i < n; i++) {
      memo[n] += solve(i) * solve(n - i - 1);
    }
    return memo[n];
  }
  int numTrees(int n) {
    memset(&memo, 0, sizeof(memo));
    memo[0] = 1;
    memo[1] = 1;
    return solve(n);
  }
};
