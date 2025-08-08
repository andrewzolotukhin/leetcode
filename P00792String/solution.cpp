class Solution {
private:
  bool isMatch(string &p, string &w) {
    int pi = 0, wi = 0;
    while (pi < p.size() && wi < w.size()) {
      if (p[pi] == w[wi]) {
        wi++;
      }
      pi++;
    }
    return (wi == w.size());
  }

public:
  int numMatchingSubseq(string s, vector<string> &words) {
    int ans = 0;
    unordered_map<string, bool> memo;
    for (auto w : words) {
      if (memo.count(w) && memo[w]) {
        ans++;
      } else if (memo[w] = isMatch(s, w)) {
        ans++;
      }
    }
    return ans;
  }
};
