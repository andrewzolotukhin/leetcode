class Solution {
public:
  long long minimumCost(string source, string target, vector<char> &original,
                        vector<char> &changed, vector<int> &cost) {
    vector<vector<long long>> c(26, vector<long long>(26, INT_MAX));

    for (int i = 0; i < original.size(); i++) {
      c[original[i] - 'a'][changed[i] - 'a'] =
          min(c[original[i] - 'a'][changed[i] - 'a'], (long long)cost[i]);
    }

    for (int k = 0; k < 26; k++) {
      for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
          c[i][j] = min(c[i][j], c[i][k] + c[k][j]);
        }
      }
    }

    long long ans = 0LL;

    for (int i = 0; i < source.size(); i++) {
      if (source[i] == target[i])
        continue;
      int c1 = source[i] - 'a';
      int c2 = target[i] - 'a';
      if (c[c1][c2] < INT_MAX) {
        ans += c[c1][c2];
      } else {
        return -1;
      }
    }

    return ans;
  }
};
