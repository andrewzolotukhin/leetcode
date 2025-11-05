class Solution {
public:
  int missingNumber(vector<int> &nums) {
    int sum = nums.size() * (nums.size() + 1) / 2;
    for (auto &v : nums)
      sum -= v;
    return sum;
  }
};
