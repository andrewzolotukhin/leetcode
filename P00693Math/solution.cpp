class Solution {
public:
  bool hasAlternatingBits(int n) {
    unsigned int v = 0;
    bool shouldadd = true;
    for (int i = 0; i < 32; i++) {
      if (n == v)
        return true;

      v = 2 * v + (shouldadd ? 1 : 0);
      shouldadd = !shouldadd;
    }
    return false;
  }
};
