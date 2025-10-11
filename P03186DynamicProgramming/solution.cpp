class Solution {
public:
  long long maximumTotalDamage(vector<int> &power) {
    map<int, int> freq;
    for (auto p : power)
      freq[p]++;

    vector<pair<int, int>> v = {{INT_MIN, 0}};
    for (auto &p : freq) {
      v.push_back(p);
    }

    int n = v.size();
    vector<long long> dp(n, 0);
    long long m = 0;

    for (int i = 1, j = 1; i < n; i++) {
      while (j < i && v[j].first < v[i].first - 2) {
        m = max(m, dp[j]);
        j++;
      }
      dp[i] = m + 1LL * v[i].first * v[i].second;
    }

    long long ans = 0;
    for (int i = 1; i < n; i++) {
      ans = max(ans, dp[i]);
    }

    return ans;
  }
};
