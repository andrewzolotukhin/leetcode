class Solution {
public:
  int smallestNumber(int n) {
    int a = 1;
    while (a < n)
      a = (a << 1) | 1;
    return a;
  }
};
