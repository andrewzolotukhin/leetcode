class Solution {
public:
  int minImpossibleOR(vector<int> &nums) {
    unordered_set s(nums.begin(), nums.end());
    int t = 1;
    while (s.count(t)) {
      t <<= 1;
    }
    return t;
  }
};
