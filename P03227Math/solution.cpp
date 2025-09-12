class Solution {
private:
  inline bool isVovel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
  }

public:
  bool doesAliceWin(string s) {
    int vc = 0;
    for (auto c : s)
      vc += isVovel(c);
    if (vc == 0)
      return false;
    return true;
  }
};
