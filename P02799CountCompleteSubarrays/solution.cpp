class Solution {
public:
  int countCompleteSubarrays(vector<int> &nums) {
    int total = 0, n = nums.size();
    unordered_set<int> t(nums.begin(), nums.end());
    unordered_map<int, int> c;
    total = t.size();
    int j = 0;
    int ans = 0;

    for (int i = 0; i < n; i++) {
      if (i > 0) {
        c[nums[i - 1]]--;
        if (c[nums[i - 1]] == 0) {
          c.erase(nums[i - 1]);
        }
      }
      while (j < n && c.size() < total) {
        c[nums[j++]]++;
      }
      if (c.size() == total) {
        ans += n - j + 1;
      }
    }
    return ans;
  }
};
