class Solution {
private:
  long long pow2(long long n, int mod) {
    long long ans = 1;
    long long base = 2;
    if (n < 60) {
      return (1LL << (n)) % mod;
    }

    while (n > 0) {
      if (n & 1) {
        ans = (ans * base) % mod;
      }
      base = (base * base) % mod;
      n /= 2;
    }

    return ans;
  }
  void combinations(int current, int minFreq) {
    if (used.size() > 1) {
      long long r = 1;
      for (auto u : used) {
        r = (r * freq[u]) % mod;
      }
      ans += r;
    }
    for (int i = minFreq; i < freq.size(); i++) {
      if (freq[i] == 0 || (factors[i] & current) != 0)
        continue;
      used.insert(i);
      combinations(current | factors[i], i + 1);
      used.erase(i);
    }
  }
  vector<long long> factors = {
      0,               // 0
      0,               // 1
      0b10,            // 2
      0b100,           // 3
      0,               // 4
      1 << 4,          // 5
      0b110,           // 6
      1 << 6,          // 7
      0,               // 8
      0,               // 9
      0b10010,         // 10
      1 << 10,         // 11
      0,               // 12
      1 << 12,         // 13
      0b1000010,       // 14
      0b10100,         // 15
      0,               // 16
      1 << 16,         // 17
      0,               // 18
      1 << 18,         // 19
      0,               // 20
      0b1000100,       // 21
      0b10000000010,   // 22
      1 << 22,         // 23
      0,               // 24
      0,               // 25
      0b1000000000010, // 26
      0,               // 27
      0,               // 28
      1 << 28,         // 29
      0b10110          // 30
  };
  int mod = int(1e9) + 7;
  vector<int> freq;
  unordered_set<int> used;
  long long ans = 0;

public:
  int numberOfGoodSubsets(vector<int> &nums) {

    freq = vector<int>(31, 0);
    int ones = 0;
    // long long ans = 0;
    for (auto n : nums) {
      if (n == 1)
        ones++;
      if (factors[n]) {
        freq[n]++;
      }
    }

    for (int i = 0; i < freq.size(); i++) {
      ans += freq[i];
    }
    ans %= mod;
    combinations(0, 2);
    return ((ans % mod) * pow2(ones, mod)) % mod;
  }
};
