class Solution {
public:
  int makeTheIntegerZero(int num1, int num2) {
    int a = 1;
    while (true) {
      long long v = num1 - (long long)(num2)*a;
      if (v < a) {
        return -1;
      }
      if (a >= __builtin_popcountll(v))
        return a;

      a++;
    }
  }
};
