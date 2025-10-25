class Solution {
private:
  string addStrings(const string &a, const string &b) {
    int i = (int)a.size() - 1;
    int j = (int)b.size() - 1;
    int carry = 0;
    string res;
    while (i >= 0 || j >= 0 || carry) {
      int da = (i >= 0) ? (a[i] - '0') : 0;
      int db = (j >= 0) ? (b[j] - '0') : 0;
      int s = da + db + carry;
      res.push_back(char('0' + (s % 10)));
      carry = s / 10;
      i--;
      j--;
    }
    reverse(res.begin(), res.end());
    return res;
  }

  int cmpNumStr(const string &a, const string &b) {
    if (a.size() != b.size())
      return (a.size() < b.size()) ? -1 : 1;
    if (a == b)
      return 0;
    return (a < b) ? -1 : 1;
  }

  bool isGood(string &val, string &prev, int start, string &num) {
    int n = num.size();
    string v = "";
    for (int i = start; i < n; i++) {
      if (i > start && num[start] == '0')
        break;
      v += num[i];
      auto cmp = cmpNumStr(v, val);
      if (cmp == 0) {
        if (i == n - 1)
          return true;
        string a = addStrings(prev, v);
        if (isGood(a, v, i + 1, num))
          return true;
      } else if (cmp > 0)
        break;
    }

    return false;
  }

public:
  bool isAdditiveNumber(string num) {
    int n = num.size();

    for (int i = 0; i < n - 2; i++) {
      if (i > 0 && num[0] == '0')
        break;
      auto left = num.substr(0, i + 1);
      for (int j = i + 1; j < n - 1; j++) {
        if (j > i + 1 && num[i + 1] == '0')
          break;
        auto right = num.substr(i + 1, j - i);
        string a = addStrings(left, right);
        if (isGood(a, right, j + 1, num))
          return true;
      }
    }

    return false;
  }
};
