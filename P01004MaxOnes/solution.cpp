class Solution {
public:
  int longestOnes(vector<int> &nums, int k) {
    int ans = 0;
    int zc = 0, l = 0;
    for (int r = 0; r < nums.size(); r++) {
      if (nums[r] == 0)
        zc++;
      while (zc > k) {
        if (nums[l] == 0) {
          zc--;
        }
        l++;
      }
      ans = max(ans, r - l + 1);
    }

    return ans;
  }
};
