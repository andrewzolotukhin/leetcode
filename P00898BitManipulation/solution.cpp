class Solution {
public:
  int subarrayBitwiseORs(vector<int> &arr) {
    unordered_set<int> ans, current;

    current.insert(0);

    for (auto v : arr) {
      unordered_set<int> current2;
      for (auto y : current) {
        current2.insert(v | y);
      }
      current2.insert(v);
      current = current2;
      for (auto v2 : current)
        ans.insert(v2);
    }

    return ans.size();
  }
};
