class Solution {
public:
  int duplicateNumbersXOR(vector<int> &nums) {
    unordered_map<int, int> m;
    for (auto v : nums)
      m[v]++;
    int ans = 0;
    for (auto [k, v] : m) {
      if (v == 1)
        continue;
      ans ^= k;
    }
    return ans;
  }
};
