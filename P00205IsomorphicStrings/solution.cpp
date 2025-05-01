class Solution {
public:
  bool isIsomorphic(string s, string t) {
    vector<int> l(256, 0), r(256, 0);

    for (int i = 0; i < s.size(); i++) {
      if (l[s[i]] != r[t[i]])
        return false;
      l[s[i]] = i + 1;
      r[t[i]] = i + 1;
    }

    return true;
  }
};
