class Solution {
private:
  void reverse(string &str, int s, int e) {
    int diff = e - s + 1;
    for (int i = 0; i < diff / 2; i++) {
      swap(str[s + i], str[e - i]);
    }
  }

public:
  string reverseStr(string s, int k) {
    for (int i = 0; i < s.size(); i += 2 * k) {
      reverse(s, i, min((int)s.size() - 1, i + k - 1));
    }
    return s;
  }
};
