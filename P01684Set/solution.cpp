class Solution {
public:
  int countConsistentStrings(string allowed, vector<string> &words) {
    unordered_set<char> s(allowed.begin(), allowed.end());

    int ans = 0;
    for (auto w : words) {
      bool isOk = true;
      for (auto c : w) {
        if (s.count(c) == 0) {
          isOk = false;
          break;
        }
      }
      if (isOk)
        ans++;
    }

    return ans;
  }
};
