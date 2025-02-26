class Solution {
public:
  int maxAbsoluteSum(vector<int> &nums) {
    int minC = nums[0];
    int maxC = nums[0];
    int result = max(abs(minC), abs(maxC));

    for (int i = 1; i < nums.size(); i++) {
      minC = min(nums[i], minC + nums[i]);
      maxC = max(nums[i], maxC + nums[i]);
      // cout << minC << ' ' << maxC << '\n';
      result = max(result, max(abs(minC), abs(maxC)));
    }

    return result;
  }
};
