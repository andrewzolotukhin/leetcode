class Solution {
public:
  int maxTotalFruits(vector<vector<int>> &fruits, int startPos, int k) {
    int l = 0, r = 0, n = fruits.size(), prefix = 0, ans = 0;

    auto move = [&](int left, int right) {
      if (fruits[right][0] <= startPos) {
        return startPos - fruits[left][0];
      } else if (fruits[left][0] >= startPos) {
        return fruits[right][0] - startPos;
      } else {
        return min(abs(startPos - fruits[right][0]),
                   abs(startPos - fruits[left][0])) +
               fruits[right][0] - fruits[left][0];
      }
    };

    while (r < n) {
      prefix += fruits[r][1];
      while (l <= r && move(l, r) > k) {
        prefix -= fruits[l][1];
        l++;
      }
      ans = max(ans, prefix);
      r++;
    }
    return ans;
  }
};
