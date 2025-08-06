class Solution {
public:
  vector<int> sumZero(int n) {
    vector<int> ans(n, 0);
    for (int i = 1; i <= n / 2; i++) {
      ans[i - 1] = i;
      ans[n - i] = -i;
    }
    return ans;
  }
};
