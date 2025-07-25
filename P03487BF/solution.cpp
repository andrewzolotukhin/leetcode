class Solution {
public:
  int maxSum(vector<int> &nums) {
    int n = nums.size();
    int sum = 0;
    unordered_set<int> s;
    int m = INT_MIN;

    for (int i = 0; i < n; i++) {
      m = max(m, nums[i]);
      if (nums[i] <= 0 || s.count(nums[i]))
        continue;
      sum += nums[i];
      s.insert(nums[i]);
    }

    return s.size() ? sum : m;
  }
};
