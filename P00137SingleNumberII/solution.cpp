class Solution {
public:
  int singleNumber(vector<int> &nums) {
    vector<int> bits(32, 0);

    for (auto n : nums) {
      for (int i = 0; i < 32; i++) {
        if ((uint)n & (1 << i))
          bits[i]++;
      }
    }

    int ans = 0;
    for (int i = 0; i < 32; i++) {
      ans |= ((bits[i] % 3 == 0 ? 0 : 1) << i);
    }

    return ans;
  }
};
