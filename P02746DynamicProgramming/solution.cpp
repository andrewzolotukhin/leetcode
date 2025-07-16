class Solution {
private:
  int dp[1001][27][27] = {};
  int solve(vector<string> &words, int index, char f, char l) {
    if (index == words.size())
      return 0;
    if (dp[index][f - 'a'][l - 'a'] != -1)
      return dp[index][f - 'a'][l - 'a'];

    int ans = words[index].size() + solve(words, index + 1, words[index][0], l);
    if (words[index].back() == f)
      ans--;

    int ans2 =
        words[index].size() + solve(words, index + 1, f, words[index].back());

    if (words[index][0] == l)
      ans2--;

    return dp[index][f - 'a'][l - 'a'] = min(ans, ans2);
  }

public:
  int minimizeConcatenatedLength(vector<string> &words) {
    memset(dp, -1, sizeof(dp));
    return words[0].size() +
           solve(words, 1, words[0][0], words[0][words[0].size() - 1]);
  }
};
