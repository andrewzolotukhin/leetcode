class Solution {
public:
  int maxDistinctElements(vector<int> &nums, int k) {
    sort(nums.begin(), nums.end());
    int ans = 0, previous = INT_MIN;

    for (int i = 0; i < nums.size(); i++) {
      int c = min(max(nums[i] - k, previous + 1), nums[i] + k);
      if (c > previous) {
        ans++;
        previous = c;
      }
    }

    return ans;
  }
};
