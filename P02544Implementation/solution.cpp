class Solution {
public:
  int alternateDigitSum(int n) {
    int ans = 0;
    int m = (int)log10(n) % 2 ? -1 : 1;
    while (n) {
      int r = n % 10;
      ans += m * r;
      m *= -1;
      n /= 10;
    }
    return ans;
  }
};
