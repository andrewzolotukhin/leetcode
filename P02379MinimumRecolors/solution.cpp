class Solution {
public:
  int minimumRecolors(string blocks, int k) {
    int r = 0;

    for (int i = 0; i < k; i++) {
      if (blocks[i] == 'W') {
        r++;
      }
    }

    int rr = r;

    for (int i = k; i < blocks.size(); i++) {
      if (blocks[i - k] == 'W') {
        r--;
      }
      if (blocks[i] == 'W') {
        r++;
      }
      if (r < 0)
        r = 0;
      if (r > k)
        r = k;
      rr = min(r, rr);
    }

    return rr;
  }
};
