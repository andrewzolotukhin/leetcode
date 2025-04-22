int C[10001][14] = {0}, CNT[10001][14] = {}, mod = int(1e9) + 7;

class Solution {
public:
  int idealArrays(int n, int maxValue) {
    if (C[0][0] == 0) {
      C[0][0] = 1;
      for (int i = 1; i < 10001; i++) {
        for (int k = 0; k < 14; k++) {
          if (k == 0 || k == i) {
            C[i][k] = 1;
          } else if (k > i) {
            C[i][k] = 0;
          } else {
            C[i][k] = (C[i - 1][k - 1] + C[i - 1][k]) % mod;
          }
        }
      }

      for (int div = 1; div <= 10000; ++div) { // Sieve of Eratosthenes
        ++CNT[div][0];
        for (int i = 2 * div; i <= 10000; i += div)
          for (int splits = 0; CNT[div][splits]; ++splits)
            CNT[i][splits + 1] += CNT[div][splits];
      }
    }

    int ans = 0;

    for (int i = 1; i <= maxValue; i++) {
      for (int f = 0; f < 14 && CNT[i][f] != 0; f++) {
        ans = (ans + 1LL * CNT[i][f] * C[n - 1][f]) % mod;
      }
    }

    return ans;
  }
};
