class Solution {
public:
  double findMaxAverage(vector<int> &nums, int k) {
    long sum = 0;
    for (int i = 0; i < k; i++)
      sum += nums[i];
    double ans = (double)sum / k;

    int i = k, n = nums.size();
    while (i < n) {
      sum -= nums[i - k];
      sum += nums[i];
      ans = max(ans, (double)sum / k);
      i++;
    }
    return ans;
  }
};
