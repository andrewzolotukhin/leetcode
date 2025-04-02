class Solution {
public:
  long long maximumTripletValue(vector<int> &nums) {
    int n = nums.size();

    long long ans = 0LL;

    for (int i = 0; i < n - 2; i++) {
      for (int j = i + 1; j < n - 1; j++) {
        for (int k = j + 1; k < n; k++) {
          ans = max(ans, ((long long)nums[i] - (long long)nums[j]) *
                             (long long)nums[k]);
        }
      }
    }

    return ans;
  }
};
