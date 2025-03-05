class Solution {
public:
  long long coloredCells(int n) {
    if (n == 1)
      return 1;
    if (n == 2)
      return 5;
    long long res = (n - 1LL) * (2LL + 2LL * (n - 1LL)) + 1;

    return res;
  }
};
