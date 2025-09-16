class Solution {
public:
  vector<int> findingUsersActiveMinutes(vector<vector<int>> &logs, int k) {
    unordered_map<int, unordered_set<int>> ms;
    for (auto l : logs) {
      ms[l[0]].insert(l[1]);
    }

    vector<int> ans(k, 0);
    for (auto [kk, v] : ms) {
      if (v.size() && v.size() <= k) {
        ans[v.size() - 1]++;
      }
    }

    return ans;
  }
};
