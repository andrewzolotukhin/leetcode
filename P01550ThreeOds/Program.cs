public class Solution {
    public bool ThreeConsecutiveOdds(int[] arr) {
        int cnt = 0, i = 0;
        while(i < arr.Length) {
            if(arr[i++] %2 == 1) { 
                cnt++; 
            } else cnt = 0;
            if(cnt == 3) {
                return true;
            }
        }
        return false;
    }
}
