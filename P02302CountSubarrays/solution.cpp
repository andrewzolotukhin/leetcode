class Solution {
public:
  long long countSubarrays(vector<int> &nums, long long k) {
    int n = nums.size();
    long long ans = 0LL;
    long long prefix = 0LL;
    int j = 0;
    for (int i = 0; i < n; i++) {
      prefix += nums[i];
      while (j <= i && prefix * (i - j + 1) >= k) {
        prefix -= nums[j];
        j++;
      }

      ans += i - j + 1;
    }
    return ans;
  }
};
