class Solution {
public:
  bool isTrionic(vector<int> &nums) {
    int n = nums.size();

    int i = 0, s = 0;
    do {
      i++;
      s++;
    } while (i < n && nums[i] > nums[i - 1]);
    // cout << i << '\n';
    if (i == n || s < 2)
      return false;
    s = 1;
    while (i < n && nums[i] < nums[i - 1]) {
      i++;
      s++;
    };
    // cout << i << '\n';
    if (i == n || s < 2)
      return false;
    s = 1;
    while (i < n && nums[i] > nums[i - 1]) {
      i++;
      s++;
    };
    // cout << i << '\n';
    return i == n && s >= 2;
  }
};
