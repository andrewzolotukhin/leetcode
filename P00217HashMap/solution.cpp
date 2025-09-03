class Solution {
public:
  bool containsDuplicate(vector<int> &nums) {
    unordered_map<int, int> f;
    for (auto v : nums) {
      if (f[v]++)
        return true;
    }
    return false;
  }
};
