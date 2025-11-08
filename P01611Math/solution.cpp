class Solution {
public:
  int minimumOneBitOperations(int n) {
    if (n == 0)
      return n;

    int a = 0, c = 1;
    while (c * 2 <= n) {
      c <<= 1;
      a++;
    }
    return (1 << (a + 1)) - 1 - minimumOneBitOperations(n ^ c);
  }
};
