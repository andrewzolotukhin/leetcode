class Solution {
private:
  bool canHaveAtLeast(vector<int> &nums, int k, int m) {
    int n = nums.size();
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      if (cnt == k)
        return true;
      if (nums[i] <= m) {
        cnt++;
        i++;
      }
    }
    return (cnt >= k);
  }

public:
  int minCapability(vector<int> &nums, int k) {
    int n = nums.size();
    int maxR = 0;
    int minR = 1;

    for (auto r : nums) {
      maxR = max(r, maxR);
    }

    while (minR < maxR) {
      int mid = (minR + maxR) / 2;
      if (canHaveAtLeast(nums, k, mid)) {
        maxR = mid;
      } else {
        minR = mid + 1;
      }
    }

    return minR;
  }
};
