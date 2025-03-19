class Solution {
public:
  int minOperations(vector<int> &nums) {
    int n = nums.size();
    int ans = 0;

    for (int i = 0; i <= n - 3; i++) {
      if (nums[i] == 1)
        continue;
      nums[i] = 1;
      nums[i + 1] = 1 - nums[i + 1];
      nums[i + 2] = 1 - nums[i + 2];
      ans++;
    }

    if ((nums[n - 3] == nums[n - 2]) && (nums[n - 2] == nums[n - 1])) {
      if (nums[n - 3] == 0)
        ans++;
    } else {
      return -1;
    }

    return ans;
  }
};
