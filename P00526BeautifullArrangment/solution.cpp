class Solution {
private:
  void solve(int n, vector<int> &curr, vector<int> &av, int &ans,
             vector<vector<bool>> &divisors) {
    if (curr.size() == n) {
      ans++;
      return;
    }

    for (int i = 0; i < av.size(); i++) {
      if (av[i] == -1)
        continue;
      if (divisors[av[i]][curr.size() + 1] ||
          divisors[curr.size() + 1][av[i]]) {
        curr.push_back(av[i]);
        av[i] = -1;
        solve(n, curr, av, ans, divisors);
        av[i] = curr[curr.size() - 1];
        curr.pop_back();
      }
    }
  }

public:
  int countArrangement(int n) {
    vector<vector<bool>> divisors(16, vector<bool>(16, false));
    for (int i = 1; i <= 15; i++) {
      for (int j = 1; j <= 15; j++) {
        divisors[i][j] = i >= j && i % j == 0;
      }
    }

    int ans = 0;

    vector<int> curr;
    vector<int> av;
    for (int i = 1; i <= n; i++)
      av.push_back(i);

    solve(n, curr, av, ans, divisors);

    return ans;
  }
};
