#include <boost/dynamic_bitset.hpp>

class Solution {
public:
  int minDominoRotations(vector<int> &tops, vector<int> &bottoms) {
    int n = tops.size();

    int ans = n;
    bool t = false;

    for (int i = 1; i <= 6; i++) {
      bitset<20005> bst, bsb;
      for (int j = 0; j < n; j++) {
        bst[j] = tops[j] == i;
        bsb[j] = bottoms[j] == i;
      }
      auto jo = bst | bsb;
      if (jo.count() == n) {
        t = true;
        ans = min(ans, (int)(n - max(bst.count(), bsb.count())));
      }
    }

    if (!t)
      return -1;
    return ans;
  }
};
