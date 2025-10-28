class Solution {
public:
  int nthSuperUglyNumber(int n, vector<int> &primes) {
    vector<long long> ans(n, 1);
    vector<int> index(primes.size(), 0);
    vector<long long> vals(primes.size(), 0);

    for (int i = 0; i < primes.size(); i++) {
      vals[i] = primes[i];
    }

    for (int i = 1; i < n; i++) {
      long long minEl = *min_element(vals.begin(), vals.end());
      ans[i] = minEl;
      for (int j = 0; j < primes.size(); j++) {
        if (vals[j] == minEl) {
          index[j]++;
          vals[j] = ans[index[j]] * primes[j];
        }
      }
    }
    return (int)ans[n - 1];
  }
};
