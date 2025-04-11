class Solution {
public:
  int countSymmetricIntegers(int low, int high) {
    int ans = 0;

    for (int i = low; i <= high; i++) {
      int l = log10(i) + 1;
      if (l & 1)
        continue;

      int f = 0, s = 0;
      int t = i, st = 0;
      while (t) {
        int r = t % 10;
        t /= 10;
        if (st < l / 2) {
          f += r;
        } else {
          s += r;
        }
        st++;
      }
      if (f == s)
        ans++;
    }

    return ans;
  }
};
