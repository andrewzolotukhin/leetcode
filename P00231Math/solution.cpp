class Solution {
public:
  bool isPowerOfTwo(int n) {
    for (int i = 0; i <= 33; i++) {
      if ((1LL << i) == (long long)n)
        return true;
    }
    return false;
  }
};
