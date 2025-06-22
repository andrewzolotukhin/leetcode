class Solution {
public:
  vector<string> divideString(string s, int k, char fill) {
    int n = s.size() / k + ((s.size() % k == 0) ? 0 : 1);

    vector<string> ans(n, string(k, fill));
    int idx = 0;
    int e = 0;
    for (int i = 0; i < s.size(); i++) {
      if (e >= k) {
        e = 0;
        idx++;
      }

      ans[idx][e] = s[i];
      e++;
    }
    return ans;
  }
};
