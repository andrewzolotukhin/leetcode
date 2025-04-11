class Solution {
public:
  vector<int> circularPermutation(int n, int start) {
    int len = 1 << n;
    vector<int> res(len);
    vector<int> grey(len);

    int s = 0;
    for (int i = 0; i < len; i++) {
      grey[i] = i ^ (i >> 1);
      if (grey[i] == start) {
        s = i;
      }
    }

    for (int i = 0; i < len; i++) {
      res[i] = grey[(s + i) % len];
    }

    return res;
  }
};
