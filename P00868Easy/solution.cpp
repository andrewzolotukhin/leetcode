class Solution {
public:
  int binaryGap(int n) {
    vector<int> v;
    while (n) {
      v.push_back((n & 1) ? 1 : 0);
      n >>= 1;
    }
    int idx = -1;
    for (int i = 0; i < v.size(); i++) {
      if (v[i]) {
        idx = i;
        break;
      }
    }

    if (idx == -1)
      return 0;
    int ans = 0;
    for (int i = idx + 1; i < v.size(); i++) {
      if (v[i]) {
        ans = max(i - idx, ans);
        idx = i;
      }
    }

    return ans;
  }
};
