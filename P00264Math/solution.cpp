class Solution {
public:
  int nthUglyNumber(int n) {
    set<long long> candidates = {};
    for (int i = 0; i <= 31; i++) {
      long long tw = (1LL << i);
      for (int j = 0; j <= 20; j++) {
        long long th = pow(3, j);
        if (tw * th > INT_MAX)
          continue;
        for (int k = 0; k <= 16; k++) {
          long long fi = pow(5, k);
          if (tw * th > INT_MAX / fi)
            continue;
          candidates.insert(tw * th * fi);
        }
      }
    }

    for (auto &v : candidates) {
      if (--n == 0) {
        return v;
      }
    }
    assert(false);
  }
};
