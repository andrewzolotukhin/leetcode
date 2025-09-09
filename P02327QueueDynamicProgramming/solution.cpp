class Solution {
public:
  int peopleAwareOfSecret(int n, int delay, int forget) {
    int mod = int(1e9) + 7;

    deque<int> d, f;
    d.push_back(1);
    f.push_back(1);
    long long curr = 0;

    for (int i = 0; i < n - 1; i++) {
      if (d.size() >= delay) {
        curr = (curr + d.front()) % mod;
        d.pop_front();
      }
      if (f.size() >= forget) {
        curr = (mod + curr - f.front()) % mod;
        f.pop_front();
      }
      d.push_back(curr);
      f.push_back(curr);
    }

    long long ans = 0;

    for (auto v : f) {
      ans += v;
    }

    return ans % mod;
  }
};
