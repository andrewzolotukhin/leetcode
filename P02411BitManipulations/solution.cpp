class Solution {
public:
  vector<int> smallestSubarrays(vector<int> &nums) {
    int n = nums.size();
    vector<int> positions(31, -1);
    vector<int> ans(n);

    for (int i = n - 1; i >= 0; i--) {
      int j = i;
      for (int b = 0; b < 31; b++) {
        if (!(nums[i] & (1 << b))) {
          if (positions[b] != -1) {
            j = max(j, positions[b]);
          }
        } else {
          positions[b] = i;
        }
      }
      ans[i] = j - i + 1;
    }

    return ans;
  }
};
