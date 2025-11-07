class Solution {
public:
  long long maxPower(vector<int> &stations, int r, int k) {
    int n = stations.size();
    vector<long long> count(n + 1);

    for (int i = 0; i < n; i++) {
      int le = max(0, i - r);
      int ri = min(n, i + r + 1);
      count[le] += stations[i];
      count[ri] -= stations[i];
    }

    auto chk = [&](long long v) {
      vector<long long> diff = count;
      long long sum = 0;
      long long rem = k;

      for (int i = 0; i < n; i++) {
        sum += diff[i];
        if (sum < v) {
          long long a = v - sum;
          if (rem < a)
            return false;

          rem -= a;
          int e = min(n, i + 2 * r + 1);
          diff[e] -= a;
          sum += a;
        }
      }
      return true;
    };

    long long minV = ranges::min(stations);
    long long hi = accumulate(stations.begin(), stations.end(), 0LL) + k;

    long long ans = 0;

    while (minV <= hi) {
      long long m = minV + (hi - minV) / 2;
      if (chk(m)) {
        ans = m;
        minV = m + 1;
      } else {
        hi = m - 1;
      }
    }
    return ans;
  }
};
