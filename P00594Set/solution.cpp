class Solution {
public:
  int findLHS(vector<int> &nums) {
    unordered_map<int, int> freq;
    for (auto v : nums)
      freq[v]++;
    int ans = 0;

    for (auto [k, v] : freq) {
      if (freq.count(k + 1)) {
        ans = max(ans, v + freq[k + 1]);
      }
    }

    return ans;
  }
};
