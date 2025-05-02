class Solution {
public:
  string pushDominoes(string dominoes) {
    int n = dominoes.size();
    vector<int> state(n, 0);
    int c = 0;
    for (int i = 0; i < n; i++) {
      if (dominoes[i] == 'R') {
        c = n;
      }
      if (dominoes[i] == 'L') {
        c = 0;
      }
      if (dominoes[i] == '.') {
        c = max(c - 1, 0);
      }
      state[i] += c;
    }

    string ans = string(n, '.');
    c = 0;
    for (int i = n - 1; i >= 0; i--) {
      if (dominoes[i] == 'L') {
        c = n;
      }
      if (dominoes[i] == 'R') {
        c = 0;
      }
      if (dominoes[i] == '.') {
        c = max(c - 1, 0);
      }
      state[i] -= c;
    }

    for (int i = 0; i < n; i++) {
      if (state[i] == 0)
        continue;
      ans[i] = (state[i] > 0) ? 'R' : 'L';
    }

    return ans;
  }
};
