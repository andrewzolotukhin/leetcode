class Solution {
public:
  int maximumLength(vector<int> &nums) {
    int e = 0, o = 0;
    int l = 1;
    for (int i = 0; i < nums.size(); i++) {
      int v = nums[i];
      if (v & 1) {
        o++;
      } else {
        e++;
      }
      if (i > 0) {
        if (nums[i] % 2 != nums[i - 1] % 2)
          l++;
      }
    }
    return max({e, o, l});
  }
};
