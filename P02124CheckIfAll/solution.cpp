class Solution {
public:
  bool checkString(string s) {
    int lastA = -1, firstB = -1;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == 'a')
        lastA = i;
      if (s[i] == 'a' && firstB != -1)
        return false;
      if (s[i] == 'b' && firstB == -1)
        firstB = i;
    }
    return true;
  }
};
