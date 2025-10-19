class Solution {
public:
  int countPrimes(int n) {
    int ans = 1;
    if (n <= 2)
      return 0;

    vector<int> primes(n + 1, 0);

    for (int i = 2; i * i <= n; i++) {
      int k = i * 2;
      while (k < n) {
        if (primes[k] == 0) {
          ans++;
          primes[k] = 1;
        }
        k += i;
      }
    }

    return n - ans - 1;
  }
};
