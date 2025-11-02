class Solution {
public:
  int pivotInteger(int n) {
    int total = n * (n + 1) / 2;
    int sq = (int)sqrt(total);
    if (sq * sq == total) {
      return sq;
    }
    return -1;
  }
};
