class Solution {
public:
  long long maxSubarrays(int n, vector<vector<int>> &conflictingPairs) {
    vector<int> min1(n + 1, INT_MAX), min2(n + 1, INT_MAX);

    for (auto &p : conflictingPairs) {
      int l = min(p[0], p[1]), r = max(p[0], p[1]);
      if (min1[l] > r) {
        min2[l] = min1[l];
        min1[l] = r;
      } else if (min2[l] > r) {
        min2[l] = r;
      }
    }

    long long ans = 0;
    int b1 = n, b2 = INT_MAX;
    vector<long long> del(n + 1, 0);

    for (int i = n; i >= 1; i--) {
      if (min1[b1] > min1[i]) {
        b2 = min(b2, min1[b1]);
        b1 = i;
      } else {
        b2 = min(b2, min1[i]);
      }
      ans += min(min1[b1], n + 1) - i;
      del[b1] += min(min(b2, min2[b1]), n + 1) - min(min1[b1], n + 1);
    }

    return ans + *max_element(del.begin(), del.end());
  }
};
