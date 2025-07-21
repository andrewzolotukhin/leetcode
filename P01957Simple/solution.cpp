class Solution {
public:
  string makeFancyString(string s) {
    if (s.size() < 3)
      return s;
    string ans;
    ans.push_back(s[0]);
    ans.push_back(s[1]);
    for (int i = 2; i < s.size(); i++) {
      if (s[i] == s[i - 1] && s[i - 1] == s[i - 2])
        continue;
      ans.push_back(s[i]);
    }

    return ans;
  }
};
