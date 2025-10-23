class Solution {
private:
  int solve(int n, vector<int> &memo, vector<int> &sq) {
    if (memo[n] != -1)
      return memo[n];

    int ans = INT_MAX;
    ;
    for (int i = sq.size() - 1; i >= 0; i--) {
      if (sq[i] > n)
        continue;
      if (sq[i] == n) {
        ans = 1;
        break;
      }
      ans = min(ans, 1 + solve(n - sq[i], memo, sq));
    }

    return memo[n] = ans;
  }

public:
  int numSquares(int n) {
    vector<int> memo(n + 1, -1);
    memo[0] = 0;
    vector<int> sq;
    for (int i = 1; i * i <= n; i++) {
      sq.push_back(i * i);
    }
    return solve(n, memo, sq);
  }
};
