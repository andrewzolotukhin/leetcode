int countSubarrays(int *nums, int numsSize) {
  int ans = 0;

  for (int i = 0; i < numsSize - 2; i++) {
    if (2 * (nums[i] + nums[i + 2]) == nums[i + 1]) {
      ans++;
    }
  }

  return ans;
}
