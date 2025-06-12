class Solution {
public:
  vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2) {
    unordered_set<int> s1, s2;
    for (auto n : nums1)
      s1.insert(n);
    for (auto n : nums2)
      s2.insert(n);
    vector<int> ans1, ans2;
    for (auto v : s1) {
      if (!s2.count(v))
        ans1.push_back(v);
    }
    for (auto v : s2) {
      if (!s1.count(v))
        ans2.push_back(v);
    }
    return {ans1, ans2};
  }
};
