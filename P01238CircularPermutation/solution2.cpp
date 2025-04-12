class Solution {
public:
  vector<int> circularPermutation(int n, int start) {
    int len = 1 << n;
    vector<int> res(len);

    int sg = start;
    int s = 0;
    while (sg) {
      s ^= sg;
      sg >>= 1;
    }

    for (int i = s; i < s + len; i++) {
      res[i - s] = (i % len) ^ ((i % len) >> 1);
    }

    return res;
  }
};
