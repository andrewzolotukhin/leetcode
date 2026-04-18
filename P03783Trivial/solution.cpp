class Solution {
public:
    int mirrorDistance(int n) {
        int rev = 0, o = n;
        while (n) {
            rev *= 10;
            rev += n % 10;
            n /= 10;
        }
        return abs(o - rev);
    }
};