class Solution {
public:
  bool search(vector<int> &nums, int target) {
    int n = nums.size();
    if (nums.size() == 1)
      return nums[0] == target;

    int l = 0;
    int h = n - 1;

    while (nums[l] >= nums[(l - 1 + n) % n] && (l - 1 + n) % n != 0) {
      l = (l - 1 + n) % n;
      h = (h - 1 + n) % n;
    }

    if (h < l)
      h += n;

    while (l != h) {
      int m = (l + h + 1) / 2;

      if (nums[m % n] == target) {
        return true;
      }

      if (nums[m % n] < target) {
        l = m;
      } else {
        h = m - 1;
      }
    }

    return nums[l % n] == target;
  }
};
