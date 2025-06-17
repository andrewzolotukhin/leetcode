const int MOD = int(1e9) + 7;
const int MAX = 1e5;

long long f[MAX];
long long f_inv[MAX];

class Solution {
private:
  long long powMod(long long n, int m) {
    long long ans = 1;
    while (m) {
      if (m & 1) {
        ans = (ans * n) % MOD;
      }
      n = (n * n) % MOD;
      m >>= 1;
    }
    return ans;
  }

  long long c(long long n, long long k) {
    return (((f[n] * f_inv[k]) % MOD) * f_inv[n - k]) % MOD;
  }

public:
  int countGoodArrays(int n, int m, int k) {
    if (!f[0]) {
      f[0] = 1;
      for (int i = 1; i < MAX; i++) {
        f[i] = (f[i - 1] * i) % MOD;
      }
      f_inv[MAX - 1] = powMod(f[MAX - 1], MOD - 2);
      for (int i = MAX - 1; i > 0; i--) {
        f_inv[i - 1] = (f_inv[i] * i) % MOD;
      }
    }

    return (((c(n - 1, k) * m) % MOD) * powMod(m - 1, n - k - 1)) % MOD;
  }
};
