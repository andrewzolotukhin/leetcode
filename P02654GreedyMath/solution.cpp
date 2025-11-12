class Solution {
public:
  int minOperations(vector<int> &nums) {
    int coprimes = 0, ones = nums[0] == 1 ? 1 : 0, n = nums.size();
    int gc = nums[0];
    for (int i = 1; i < nums.size(); i++) {
      gc = gcd(gc, nums[i]);
      if (nums[i] == 1)
        ones++;
    }
    if (ones > 0)
      return n - ones;
    if (gc != 1)
      return -1;

    int minL = n;
    for (int i = 0; i < n; i++) {
      int gc = 0;
      for (int j = i; j < n; j++) {
        gc = gcd(gc, nums[j]);
        if (gc == 1) {
          minL = min(minL, j - i + 1);
          break;
        }
      }
    }

    return minL + n - 2;
  }
};
