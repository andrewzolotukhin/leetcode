class Solution {
public:
  long long countSubarrays(vector<int> &nums, int minK, int maxK) {
    int n = nums.size();
    long long lastMin = -1, lastMax = -1, lastBad = -1;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      if (nums[i] == minK) {
        lastMin = i;
      }
      if (nums[i] == maxK) {
        lastMax = i;
      }
      if ((nums[i] < minK) || (nums[i] > maxK)) {
        lastBad = i;
      }

      ans += max(0LL, min(lastMin, lastMax) - lastBad);
    }

    return ans;
  }
};
