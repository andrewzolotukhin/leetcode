class Solution {
private:
  long long power(long long x, long long n, long long mod) {
    long long ans = 1;

    long long base = n;
    while (base != 0) {
      if (base & 1) {
        ans *= x;
        ans = ans % mod;
      }
      x = ((x % mod) * (x % mod)) % mod;
      base /= 2;
    }

    return ans % mod;
  }

public:
  int countGoodNumbers(long long n) {
    auto isOdd = n & 1;
    int mod = int(1e9) + 7;
    long long evenCount = (n + 1) / 2; // even 0,2,4,6,8 -> 5^evenCount
    long long oddCount = n / 2;        // prime 2,3,5,7 -> 4^oddCount

    long long ans = (power(5, evenCount, mod) * power(4, oddCount, mod)) % mod;

    return (int)ans;
  }
};
