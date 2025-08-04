class Solution {
public:
  int maximumNumberOfStringPairs(vector<string> &words) {
    multiset<string> s;
    for (auto w : words) {
      s.insert(w);
    }
    int ans = 0;
    for (auto w : words) {
      s.erase(w);
      auto c = w;
      reverse(c.begin(), c.end());
      if (s.count(c)) {
        ans++;
        s.erase(c);
      }
    }
    return ans;
  }
};
