class Solution {
private:
  int solve(int val, int n, int maxValue, unordered_map<long long, int> &memo) {
    int mod = int(1e9) + 7;
    if (val > maxValue)
      return 0;
    if (n == 1) {
      return 1;
    }
    long long key = ((long long)n << 40) | (long long)val;
    if (memo.count(key)) {
      return memo[key];
    }

    long long ans = 0LL;

    int s = 1;
    while (s * val <= maxValue) {
      ans = (ans + solve(s * val, n - 1, maxValue, memo)) % mod;
      s++;
    }

    memo[key] = ans;
    return ans;
  }

public:
  int idealArrays(int n, int maxValue) {
    unordered_map<long long, int> memo;

    int mod = int(1e9) + 7;
    long long ans = 0LL;

    for (int i = 1; i <= maxValue; i++) {
      ans = (ans + solve(i, n, maxValue, memo)) % mod;
    }

    return ans;
  }
};
