class Solution {
public:
  int getDistance(int from, int to, vector<string> &words,
                  unordered_map<int, int> &memo) {
    int key = 1000 * (from + 1) + to;
    if (memo.count(key))
      return memo[key];

    if (words[from].size() != words[to].size()) {
      return memo[key] = -1;
    }

    int diff = 0;
    for (int i = 0; i < words[from].size(); i++) {
      if (diff > 1)
        break;
      if (words[from][i] != words[to][i])
        diff++;
    }
    return memo[key] = ((diff == 1) ? 1 : -1);
  }
  vector<string> getWordsInLongestSubsequence(vector<string> &words,
                                              vector<int> &groups) {
    int n = words.size(), left = 0, right = 0;
    vector<string> ans;
    int ml = 0;
    unordered_map<int, int> memo;

    vector<int> dp(n, 1), prev(n, -1);
    int m = 0;

    for (int i = 1; i < n; i++) {
      for (int j = 0; j < i; j++) {
        if (groups[i] != groups[j] && dp[j] + 1 > dp[i] &&
            getDistance(i, j, words, memo) == 1) {
          dp[i] = dp[j] + 1;
          prev[i] = j;
        }
      }
      if (dp[i] > dp[m]) {
        m = i;
      }
    }

    for (int i = m; i >= 0; i = prev[i]) {
      ans.push_back(words[i]);
    }
    reverse(ans.begin(), ans.end());

    return ans;
  }
};
