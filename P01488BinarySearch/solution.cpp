class Solution {
public:
  vector<int> avoidFlood(vector<int> &rains) {
    int n = rains.size();
    vector<int> ans(n, 1);
    set<int> s;

    unordered_map<int, int> m;

    for (int i = 0; i < n; i++) {
      int r = rains[i];

      if (r) {
        ans[i] = -1;
        if (m.count(r)) {
          auto it = s.lower_bound(m[r]);
          if (it == s.end()) {
            return {};
          }

          ans[*it] = rains[i];
          s.erase(it);
        }
        m[r] = i;
      } else {
        s.insert(i);
      }
    }
    return ans;
  }
};
