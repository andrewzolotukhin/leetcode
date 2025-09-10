class Solution {
public:
  vector<vector<int>> groupThePeople(vector<int> &groupSizes) {
    vector<pair<int, int>> ps;
    int n = groupSizes.size();
    for (int i = 0; i < n; i++)
      ps.push_back({groupSizes[i], i});
    sort(ps.begin(), ps.end());
    vector<vector<int>> ans;
    vector<int> g;
    for (int i = 0; i < n; i++) {
      g.push_back(ps[i].second);
      if (g.size() == ps[i].first) {
        ans.push_back(g);
        g = {};
      }
    }

    return ans;
  }
};
