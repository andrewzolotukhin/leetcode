class Solution {
private:
  long long getVal(long long num) {
    long long res = 0;
    while (num) {
      long long rem = 1LL * (num % 10);
      res += rem * rem;
      num /= 10;
    }
    return res;
  }

public:
  bool isHappy(int n) {
    long long k = n;
    unordered_map<long long, long long> dp;
    while (k != 1) {
      if (dp.count(k))
        return false;
      auto r = getVal(k);
      dp[k] = r;
      k = r;
    }
    return true;
  }
};
