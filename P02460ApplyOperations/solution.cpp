class Solution {
public:
  vector<int> applyOperations(vector<int> &nums) {
    int n = nums.size();

    for (int i = 0; i < n - 1; i++) {
      if (nums[i] == nums[i + 1]) {
        nums[i] *= 2;
        nums[i + 1] = 0;
      }
    }

    int nextZero = n - 1;
    while (nextZero > 0 && nums[nextZero] == 0) {
      nextZero--;
    }

    vector<int> result(n, 0);
    int s = 0;
    for (auto v : nums) {
      if (v != 0) {
        result[s++] = v;
      }
    }

    return result;
  }
};
