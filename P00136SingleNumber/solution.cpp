class Solution {
public:
  int singleNumber(vector<int> &nums) {
    int ans = 0;
    for (auto r : nums)
      ans ^= r;

    return ans;
  }
};
