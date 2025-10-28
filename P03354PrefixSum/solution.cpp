class Solution {
public:
  int countValidSelections(vector<int> &nums) {
    int n = nums.size();
    vector<int> prefix(n + 1, 0);

    for (int i = 0; i < n; i++) {
      prefix[i + 1] = prefix[i] + nums[i];
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (nums[i] != 0)
        continue;
      int left = prefix[i];
      int right = prefix[n] - prefix[i + 1];
      if (left == right) {
        ans += 2;
      } else if (abs(left - right) == 1) {
        ans += 1;
      }
    }
    return ans;
  }
};
