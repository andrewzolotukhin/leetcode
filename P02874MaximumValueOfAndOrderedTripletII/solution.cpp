class Solution {
public:
  long long maximumTripletValue(vector<int> &nums) {
    int n = nums.size();
    vector<int> pref(n, nums[0]), suff(n, nums[n - 1]);
    for (int i = 1; i < n; i++) {
      pref[i] = max(pref[i - 1], nums[i]);
      suff[n - 1 - i] = max(suff[n - i], nums[n - 1 - i]);
    }

    long long ans = 0;
    for (int j = 1; j < n - 1; j++) {
      ans = max(ans, ((long long)(pref[j - 1]) - (long long)nums[j]) *
                         (long long)suff[j + 1]);
    }

    return ans;
  }
};
