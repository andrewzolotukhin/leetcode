public class Solution {
    public int RemoveDuplicates(int[] nums) {
        int i = 0;
        foreach(var num in nums) {
            if(i < 2 || nums[i-2] < num) {
                nums[i++] = num;
            }
        }
        return i;
    }
}
