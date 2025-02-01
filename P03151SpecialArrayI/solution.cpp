class Solution {
public:
  bool isArraySpecial(vector<int> &nums) {
    for (int i = 1; i < nums.size(); i += 2) {
      if ((nums[i - 1] % 2 == nums[i] % 2) ||
          (i + 1 < nums.size() && nums[i] % 2 == nums[i + 1] % 2)) {
        return false;
      }
    }
    return true;
  }
};
