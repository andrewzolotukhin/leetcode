class Solution {
public:
  vector<int> recoverOrder(vector<int> &order, vector<int> &friends) {
    unordered_map<int, int> m;
    for (int i = 0; i < order.size(); i++) {
      m[order[i]] = i + 1;
    }

    vector<pair<int, int>> fo;
    for (int i = 0; i < friends.size(); i++) {
      fo.push_back({m[friends[i]], friends[i]});
    }
    sort(fo.begin(), fo.end());
    vector<int> ans;
    for (auto f : fo) {
      ans.push_back(f.second);
    }

    return ans;
  }
};
