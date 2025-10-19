class Solution {
public:
  string findLexSmallestString(string s, int a, int b) {
    int n = s.size();
    vector<int> saw(n);

    string ans = s;

    s = s + s;

    for (int i = 0; saw[i] == 0; i = (i + b) % n) {
      saw[i] = 1;
      for (int j = 0; j < 10; j++) {
        int lim = b % 2 == 0 ? 0 : 9;
        for (int k = 0; k <= lim; k++) {
          auto t = s.substr(i, n);
          for (int p = 1; p < n; p += 2) {
            t[p] = '0' + (t[p] - '0' + j * a) % 10;
          }

          for (int p = 0; p < n; p += 2) {
            t[p] = '0' + (t[p] - '0' + k * a) % 10;
          }
          ans = min(ans, t);
        }
      }
    }
    return ans;
  }
};
