class Solution {
public:
  int numberOfBeams(vector<string> &bank) {
    int n = bank.size(), m = bank[0].size(), ans = 0;
    int prevc = 0;
    for (int i = 0; i < m; i++) {
      if (bank[0][i] == '1')
        prevc++;
    }

    for (int i = 1; i < n; i++) {
      int c = 0;
      for (int j = 0; j < m; j++) {
        if (bank[i][j] == '1')
          c++;
      }

      if (c == 0)
        continue;
      ans += prevc * c;
      prevc = c;
    }
    return ans;
  }
};
