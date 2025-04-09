class Solution {
public:
  int minOperations(vector<int> &nums, int k) {
    sort(nums.begin(), nums.end(), greater<int>());

    int i = 1, n = nums.size(), ans = 0;
    for (auto v : nums) {
      if (v < k) {
        return -1;
      }
    }

    while (i < n && nums[i] >= k) {
      if (nums[i] == nums[i - 1]) {
        i++;
        continue;
      }
      i++;
      ans++;
    }

    if (i == n && k < nums[n - 1])
      ans++;

    return ans;
  }
};
