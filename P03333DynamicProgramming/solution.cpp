int MOD = int(1e9) + 7;

class Solution {
public:
  int possibleStringCount(string word, int k) {
    int ans = 1;
    int n = word.size();

    vector<int> dupls;
    int l = 1;

    for (int i = 1; i < n; i++) {
      if (word[i] == word[i - 1]) {
        l++;
      } else {
        dupls.push_back(l);
        l = 1;
      }
    }
    dupls.push_back(l);

    for (int d : dupls) {
      ans = ((long long)ans * d) % MOD;
    }

    if (dupls.size() >= k)
      return ans;

    vector<int> f(k), g(k, 1);
    f[0] = 1;

    for (int i = 0; i < dupls.size(); i++) {
      vector<int> fn(k);
      for (int j = 1; j < k; j++) {
        fn[j] = g[j - 1];
        if (j - dupls[i] - 1 >= 0) {
          fn[j] = ((long long)fn[j] - g[j - dupls[i] - 1] + MOD) % MOD;
        }
      }

      vector<int> gn(k);
      gn[0] = fn[0];
      for (int j = 1; j < k; j++) {
        gn[j] = ((long long)gn[j - 1] + fn[j]) % MOD;
      }
      f = move(fn);
      g = move(gn);
    }

    return (ans - g[k - 1] + MOD) % MOD;
  }
};
