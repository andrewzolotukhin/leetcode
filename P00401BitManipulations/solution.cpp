class Solution {
public:
  vector<string> readBinaryWatch(int turnedOn) {
    vector<string> ans;
    for (int h = 0; h < 12; h++) {
      for (int m = 0; m < 60; m++) {
        if ((__builtin_popcount(h) + __builtin_popcount(m) == turnedOn)) {
          string s = to_string(h);
          string hs = to_string(m);
          if (hs.size() < 2)
            hs = "0" + hs;
          ans.push_back(s + ":" + hs);
        }
      }
    }
    return ans;
  }
};
