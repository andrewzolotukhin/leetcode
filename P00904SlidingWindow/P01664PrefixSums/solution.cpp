class Solution {
public:
  int waysToMakeFair(vector<int> &nums) {
    int n = nums.size();
    vector<int> prefixE(n + 1, 0), prefixO(n + 1, 0);
    for (int i = 0; i < n; i++) {
      if (i & 1) {
        prefixE[i + 1] = prefixE[i];
        prefixO[i + 1] = prefixO[i] + nums[i];
      } else {
        prefixE[i + 1] = prefixE[i] + nums[i];
        prefixO[i + 1] = prefixO[i];
      }
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {
      int evenBefore, evenAfter, oddBefore, oddAfter;
      if (i & 1) {
        evenBefore = prefixE[i];
        evenAfter = prefixO[n] - prefixO[i + 1];
        oddBefore = (i > 1) ? (prefixO[i - 1]) : 0;
        oddAfter = prefixE[n] - prefixE[i + 1];
      } else {
        evenBefore = prefixE[i];
        evenAfter = prefixO[n] - prefixO[i + 1];
        oddBefore = prefixO[i];
        oddAfter = prefixE[n] - prefixE[i + 1];
      }
      if (evenBefore + evenAfter == oddBefore + oddAfter)
        ans++;
    }
    return ans;
  }
};
