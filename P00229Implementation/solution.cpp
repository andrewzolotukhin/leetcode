class Solution {
public:
  vector<int> majorityElement(vector<int> &nums) {
    unordered_map<int, int> m;
    for (auto &num : nums)
      m[num]++;

    vector<int> ans;
    int n = nums.size() / 3;

    for (auto [k, v] : m) {
      if (v > n)
        ans.push_back(k);
    }

    return ans;
  }
};
