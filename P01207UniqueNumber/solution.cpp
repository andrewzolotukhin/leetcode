class Solution {
public:
  bool uniqueOccurrences(vector<int> &arr) {
    unordered_map<int, int> m;
    for (auto v : arr) {
      m[v]++;
    }

    unordered_set<int> s;
    for (auto [k, v] : m) {
      s.insert(v);
    }

    return m.size() == s.size();
  }
};
