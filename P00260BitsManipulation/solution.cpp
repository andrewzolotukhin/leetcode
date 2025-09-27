class Solution {
public:
  vector<int> singleNumber(vector<int> &nums) {
    long long x = 0;
    for (auto v : nums) {
      x ^= v;
    }

    vector<int> ans(2);
    x &= -x;
    for (auto v : nums) {
      if (x & v) {
        ans[0] ^= v;
      } else {
        ans[1] ^= v;
      }
    }

    return ans;
  }
};
