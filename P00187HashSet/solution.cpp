class Solution {
private:
  inline char getCode(char c) {
    if (c == 'A')
      return 0;
    if (c == 'C')
      return 1;
    if (c == 'G')
      return 2;
    return 3;
  }
  inline char decode(char c) {
    if (c == 0)
      return 'A';
    if (c == 1)
      return 'C';
    if (c == 2)
      return 'G';
    return 'T';
  }

public:
  vector<string> findRepeatedDnaSequences(string s) {
    if (s.size() <= 10)
      return {};

    long long trim = (1LL << 20) - 1;
    unordered_map<long long, int> set;
    long long v = 0;
    for (int i = 0; i < 10; i++) {
      v <<= 2;
      v += getCode(s[i]);
    }

    set[v]++;
    for (int i = 10; i < s.size(); i++) {
      v <<= 2;
      v &= trim;
      v += getCode(s[i]);
      set[v]++;
    }

    vector<string> ans;
    for (auto [k, v] : set) {
      if (v <= 1)
        continue;
      long long kk = k;
      string r(10, ' ');

      for (int i = 9; i >= 0; i--) {
        char c = 3 & kk;
        r[i] = decode(c);
        kk >>= 2;
      }
      ans.push_back(r);
    }

    return ans;
  }
};
