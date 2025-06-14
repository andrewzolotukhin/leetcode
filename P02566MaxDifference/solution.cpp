class Solution {
public:
  int minMaxDifference(int num) {
    auto s = to_string(num);
    int i = 0;
    for (i = 0; i < s.size(); i++) {
      if (s[i] != '9')
        break;
    }
    int maxV = num, minV;
    if (i != s.size()) {
      char si = s[i];
      for (int j = 0; j < s.size(); j++) {
        if (s[j] == si)
          s[j] = '9';
      }
      maxV = stoi(s);
    }
    s = to_string(num);

    char si = s[0];
    for (int j = 0; j < s.size(); j++) {
      if (s[j] == si)
        s[j] = '0';
    }
    minV = stoi(s);
    return maxV - minV;
  }
};
