class Solution {
public:
  bool hasIncreasingSubarrays(vector<int> &nums, int k) {
    unordered_set<int> starts;
    for (int i = 0; i < nums.size() - k + 1; i++) {
      int prev = nums[i];
      bool inc = true;
      for (int j = 1; j < k; j++) {
        if (nums[i + j] <= prev) {
          inc = false;
          break;
        }
        prev = nums[i + j];
      }
      if (inc) {
        if (starts.count(i - k)) {
          return true;
        }
        starts.insert(i);
      }
    }
    return false;
  }
};
