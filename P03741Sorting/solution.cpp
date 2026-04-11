class Solution {
public:
  int minimumDistance(vector<int> &nums) {
    int ans = INT_MAX, n = nums.size();
    vector<pair<int, int>> pairs;
    for (int i = 0; i < n; i++) {
      pairs.push_back({nums[i], i});
    }
    sort(pairs.begin(), pairs.end());

    for (int i = 0; i < n - 2; i++) {
      if (pairs[i].first == pairs[i + 1].first &&
          pairs[i].first == pairs[i + 2].first) {
        ans = min(ans, -2 * pairs[i].second + 2 * pairs[i + 2].second);
      }
    }

    if (ans == INT_MAX)
      return -1;
    return ans;
  }
};
