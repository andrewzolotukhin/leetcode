class Solution {
private:
  int reverse(int a) {
    int x = 0;
    while (a) {
      x *= 10;
      x += a % 10;
      a = a / 10;
    }
    return x;
  }

public:
  int countDistinctIntegers(vector<int> &nums) {
    unordered_set<int> ans;
    for (auto n : nums)
      ans.insert(n);
    for (auto n : nums)
      ans.insert(reverse(n));
    return ans.size();
  }
};
