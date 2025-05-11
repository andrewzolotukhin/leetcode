class Solution {
public:
  vector<int> minCosts(vector<int> &cost) {
    int n = cost.size();
    vector<int> ans(n, INT_MAX);

    for (int i = 0; i < n; i++) {
      ans[i] = min(ans[i], cost[i]);
      for (int j = 0; j < i; j++) {
        ans[i] = min(ans[j], ans[i]);
      }
    }

    return ans;
  }
};
