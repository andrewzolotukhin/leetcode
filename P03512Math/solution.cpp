class Solution {
public:
  int minOperations(vector<int> &nums, int k) {
    int sum = 0;
    for (auto v : nums)
      sum += v;
    return sum % k;
  }
};
