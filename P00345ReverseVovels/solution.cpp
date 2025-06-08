class Solution {
public:
  string reverseVowels(string s) {
    stack<char> v;
    auto isVovel = [&](char c) {
      return c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' ||
             c == 'I' || c == 'o' || c == 'O' || c == 'u' || c == 'U';
    };
    for (int i = 0; i < s.size(); i++) {
      if (isVovel(s[i])) {
        v.push(s[i]);
        s[i] = '\0';
      }
    }
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '\0') {
        s[i] = v.top();
        v.pop();
      }
    }
    return s;
  }
};
