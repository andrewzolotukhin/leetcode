class Solution {
public:
  vector<int> twoSum(vector<int> &numbers, int target) {
    for (int i = 0; i < numbers.size() - 1; i++) {
      int newTarget = target - numbers[i];

      int r = lower_bound(numbers.begin() + i + 1, numbers.end(), newTarget) -
              numbers.begin();
      // cout << numbers[i] << " need to find " << newTarget << " found " << r
      // << " with value " << numbers[r] << '\n';
      if (r < numbers.size() && numbers[r] == newTarget) {
        return {i + 1, r + 1};
      }
    }
    assert(false);
  }
};
