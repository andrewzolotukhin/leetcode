class Solution {
public:
  int maximumUniqueSubarray(vector<int> &nums) {
    int n = nums.size(), l = 0, curr = 0;

    unordered_map<int, bool> m;
    int ans = 0;

    for (int r = 0; r < n; r++) {
      while (m[nums[r]]) {
        curr -= nums[l];
        m[nums[l]] = false;
        l++;
      }
      curr += nums[r];
      m[nums[r]] = true;
      if (curr > ans)
        ans = curr;
    }

    return ans;
  }
};
