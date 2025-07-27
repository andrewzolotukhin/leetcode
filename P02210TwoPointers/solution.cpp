class Solution {
public:
  int countHillValley(vector<int> &nums) {
    int ans = 0, n = nums.size();
    vector<int> a = {nums[0]};
    for (int i = 1; i < n; i++) {
      if (nums[i] == nums[i - 1])
        continue;
      a.push_back(nums[i]);
    }

    for (int i = 1; i < a.size() - 1; i++) {
      if (a[i - 1] > a[i] && a[i] < a[i + 1])
        ans++;
      if (a[i - 1] < a[i] && a[i + 1] < a[i])
        ans++;
    }

    return ans;
  }
};
