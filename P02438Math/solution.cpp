class Solution {
private:
  long long powMod(long long n, long long e, long long p) {
    long long ans = 1LL;
    long long b = n;
    while (e) {
      if (e & 1) {
        ans = (ans * b) % p;
      }
      b = (b * b) % p;
      e /= 2;
    }
    return ans;
  }
  long long modInv(long long n, long long p) {
    if (n == 1)
      return n;
    return powMod(n, p - 2, p);
  }

public:
  vector<int> productQueries(int n, vector<vector<int>> &queries) {
    int mod = int(1e9) + 7;
    int m = queries.size();
    vector<int> ans(m);
    vector<long long> prefix = {1LL};
    vector<long long> powers;
    for (int i = 0; i < 31; i++) {
      if ((1 << i) & n) {
        powers.push_back(1 << i);
        prefix.push_back((prefix.back() * (1 << i)) % mod);
      }
    }

    for (int q = 0; q < m; q++) {
      int l = queries[q][0];
      int r = queries[q][1];
      ans[q] = (prefix[r + 1] * modInv(prefix[l], mod)) % mod;
    }
    return ans;
  }
};
