class Solution {
public:
  bool hasAllCodes(string s, int k) {
    int target = 1 << k;
    unordered_set<int> ss;
    if (k > s.size())
      return false;

    int c = 0;
    for (int i = 0; i < k; i++) {
      if (s[i] == '1')
        c |= 1;
      c <<= 1;
    }

    ss.insert(c);

    for (int i = k; i < s.size(); i++) {
      c &= ~(1U << k);
      if (s[i] == '1')
        c |= 1;
      c <<= 1;
      ss.insert(c);
    }

    return ss.size() == target;
  }
};
