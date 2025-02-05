class Solution {
public:
  bool areAlmostEqual(string s1, string s2) {
    int n = s1.size();
    vector<int> d;
    for (int i = 0; i < n; i++) {
      if (d.size() > 2) {
        return false;
      }
      if (s1[i] != s2[i]) {
        d.push_back(i);
      }
    }

    if (d.size() > 2)
      return false;

    if (d.size() == 0)
      return true;

    if (d.size() == 1)
      return false;

    return (s1[d[0]] == s2[d[1]]) && (s1[d[1]] == s2[d[0]]);
  }
};
