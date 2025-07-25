class Solution {
public:
  int minimizedStringLength(string s) {
    unordered_set<char> m;
    for (char c : s)
      m.insert(c);
    return m.size();
  }
};
