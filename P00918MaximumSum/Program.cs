public class Solution {
    public int MaxSubarraySumCircular(int[] nums) {
        int n = nums.Length;
        int total = 0, currMax = 0, currMin = 0, minSum = nums[0], maxSum = nums[0];
        for(int i = 0 ; i < n; i++) {
            total += nums[i];

            currMax = Math.Max(nums[i], currMax + nums[i]);
            maxSum = Math.Max(maxSum, currMax);

            currMin = Math.Min(nums[i], currMin + nums[i]);
            minSum = Math.Min(minSum, currMin);

        }

        if(total == minSum) return maxSum;

        return Math.Max(maxSum, total - minSum);
    }
}
