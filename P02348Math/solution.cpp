class Solution {
public:
  long long zeroFilledSubarray(vector<int> &nums) {
    long long ans = 0;
    int n = nums.size();

    for (int i = 0; i < n;) {
      if (nums[i] != 0) {
        i++;
        continue;
      }
      long long c = 0;
      int j = i;
      while (j < n && nums[j] == 0)
        c++, j++;
      ans += c * (c + 1) / 2;
      i = j;
    }
    return ans;
  }
};
