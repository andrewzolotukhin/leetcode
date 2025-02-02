class Solution {
public:
  bool check(vector<int> &nums) {
    int n = nums.size();
    int minI = -1;
    int min = INT_MAX;
    for (int i = 0; i < n; i++) {
      if (nums[i] < min) {
        min = nums[i];
        minI = i;
      }
    }

    while (nums.size() > 1 && nums[0] == nums[nums.size() - 1]) {
      nums.pop_back();
    }

    n = nums.size();

    for (int i = 0; i < n - 1; i++) {
      if (nums[(minI + i + 1) % n] < nums[(minI + i) % n])
        return false;
    }

    return true;
  }
};
