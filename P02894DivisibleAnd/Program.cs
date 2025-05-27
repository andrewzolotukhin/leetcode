public class Solution {
    public int DifferenceOfSums(int n, int m) {
        int total = (n + 1)*n/2;
        int num2 = 0;
        for(int i = 1; i <= n; i++) num2 += (i%m == 0)?i:0;
        return total-num2-num2;

        // the faster way is:
        // int k = n / m;
        // return n * (n + 1) / 2 - k * (k + 1) * m;
    }
}
