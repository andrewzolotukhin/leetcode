class Solution {
public:
  int maximumGap(vector<int> &nums) {
    if (nums.size() < 2)
      return 0;

    int minV = nums[0], maxV = nums[0];
    for (auto v : nums) {
      minV = min(minV, v);
      maxV = max(maxV, v);
    }

    int g = ceil((double)(maxV - minV) / (nums.size() - 1));

    vector<int> minBuckets(nums.size() - 1, INT_MAX);
    vector<int> maxBuckets(nums.size() - 1, INT_MIN);

    for (int n : nums) {
      if (n == minV || n == maxV)
        continue;

      int i = (n - minV) / g;

      minBuckets[i] = min(n, minBuckets[i]);
      maxBuckets[i] = max(n, maxBuckets[i]);
    }

    int ans = 0;
    int prev = minV;
    for (int i = 0; i < nums.size() - 1; i++) {
      if (minBuckets[i] == INT_MAX && maxBuckets[i] == INT_MIN)
        continue;

      ans = max(ans, minBuckets[i] - prev);
      prev = maxBuckets[i];
    }
    return max(ans, maxV - prev);
  }
};
