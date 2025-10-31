class Solution {
public:
  int maxScore(vector<int> &nums) {
    sort(nums.rbegin(), nums.rend());
    int n = nums.size();
    vector<long long> prefix(n + 1, 0LL);
    int ans = 0;
    for (int i = 0; i < n; i++) {
      prefix[i + 1] = prefix[i] + nums[i];
      if (prefix[i + 1] > 0)
        ans++;
    }

    return ans;
  }
};
