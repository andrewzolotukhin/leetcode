class Solution {
private:
  long long getCount(int limit) {
    long long lo = 1;
    long long high = 3;
    long long c = 1;
    long ans = 0;
    while (limit >= lo) {
      ans += (min(high, (long long)limit) - lo + 1) * c;
      // cout << lo << ' ' << min(high, (long long)limit) << ' ' << c << ' ' <<
      // ans << '\n';
      high = (high + 1) * 4 - 1;
      lo *= 4;
      c++;
    }

    return ans;
  }

public:
  long long minOperations(vector<vector<int>> &queries) {
    long long ans = 0;

    for (auto q : queries) {
      int lo = q[0];
      int high = q[1];
      long long d = getCount(high) - (lo > 1 ? getCount(lo - 1) : 0);
      d = (d + 1) / 2;
      ans += d;
      // cout << "======\n";
    }

    return ans;
  }
};
