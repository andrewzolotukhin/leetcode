class Solution {
public:
  vector<int> findXSum(vector<int> &nums, int k, int x) {
    vector<int> ans;
    int n = nums.size();
    for (int i = 0; i <= n - k; i++) {
      int sum = 0;
      unordered_map<int, int> freq;

      for (int j = 0; j < k; j++) {
        freq[nums[i + j]]++;
      }

      vector<pair<int, int>> els;
      for (auto &[k, v] : freq) {
        els.push_back({v, k});
      }

      // better to use priority_queue here, but constraints are very small
      sort(els.begin(), els.end(), [&](pair<int, int> &a, pair<int, int> &b) {
        if (a.first == b.first) {
          return a.second > b.second;
        }
        return a.first > b.first;
      });

      for (int j = 0; j < min(x, (int)els.size()); j++) {
        sum += els[j].second * els[j].first;
      }
      ans.push_back(sum);
    }

    return ans;
  }
};
