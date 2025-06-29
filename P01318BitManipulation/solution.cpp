class Solution {
public:
  int minFlips(int a, int b, int c) {
    auto r = a | b;

    int ans = 0;
    for (int i = 0; i <= 30; i++) {
      int l = 1 << i;
      int kr = r & l;
      int kc = c & l;
      if (kr != kc) {
        if (kc == 0) {
          ans += ((a & l) ? 1 : 0) + ((b & l) ? 1 : 0);
        } else {
          ans++;
        }
      }
    }

    return ans;
  }
};
