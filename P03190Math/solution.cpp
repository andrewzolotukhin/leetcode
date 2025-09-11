class Solution {
public:
  int minimumOperations(vector<int> &nums) {
    int ans;
    for (auto x : nums)
      ans += min(3 - x % 3, x % 3);
    return ans;
  }
};
