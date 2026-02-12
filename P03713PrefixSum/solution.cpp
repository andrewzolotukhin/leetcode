class Solution {
public:
  int longestBalanced(string s) {
    if (s.size() == 1)
      return 1;
    int n = s.size();
    vector<vector<int>> prefix(n + 1, vector<int>(26, 0));

    for (int i = 0; i < n; i++) {
      prefix[i + 1] = prefix[i];
      int c = s[i] - 'a';
      prefix[i + 1][c]++;
    }

    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
      for (int j = i + 1; j < n; j++) {
        int v = 0;
        bool good = true;
        for (int k = 0; k < 26; k++) {
          int f = prefix[j + 1][k] - prefix[i][k];
          if (f == 0)
            continue;
          if (v == 0) {
            v = f;
          }
          if (f != v) {
            good = false;
            break;
          }
        }
        if (good) {
          ans = max(ans, j - i + 1);
        }
      }
    }
    return ans;
  }
};
