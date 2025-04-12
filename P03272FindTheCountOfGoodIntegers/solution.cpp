class Solution {
public:
  long long countGoodIntegers(int n, int k) {
    long long half = n / 2;
    long long ans = 0;

    long long halfMin = pow(10LL, ((long long)n - 1LL) / 2LL);
    bool isOdd = n & 1;

    unordered_set<string> knownNPalindromes;

    for (long long num = halfMin; num < 10 * halfMin; num++) {
      auto snum = to_string(num);
      string sp = snum + string(snum.rbegin() + isOdd, snum.rend());
      long long p = stoll(sp);
      if (p % k == 0) {
        sort(sp.begin(), sp.end());
        knownNPalindromes.insert(sp);
      }
    }

    vector<long long> factorials(n + 1, 1LL);

    for (int i = 2; i < n + 1; i++) {
      factorials[i] = i * factorials[i - 1];
    }

    for (auto &p : knownNPalindromes) {
      vector<int> freq(10, 0);
      for (char c : p) {
        freq[c - '0']++;
      }

      long long total = (n - freq[0]) * factorials[n - 1];
      for (int i = 0; i < 10; i++) {
        // cout << freq[i] << ' ';
        total /= factorials[freq[i]];
      }

      ans += total;
    }

    return ans;
  }
};
