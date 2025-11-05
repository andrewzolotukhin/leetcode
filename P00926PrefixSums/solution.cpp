class Solution {
public:
  int minFlipsMonoIncr(string s) {
    int n = s.size();

    vector<pair<int, int>> prefix(n + 1, {0, 0});

    for (int i = 0; i < n; i++) {
      prefix[i + 1].first = prefix[i].first + ((s[i] == '1') ? 1 : 0);
    }
    for (int i = n - 1; i >= 0; i--) {
      prefix[i].second = prefix[i + 1].second + ((s[i] == '0') ? 1 : 0);
    }

    int ans = n;

    for (int i = 0; i < n; i++) {
      int l = prefix[i + 1].first;
      int r = prefix[i].second;
      ans = min(ans, l + r - 1);
    }
    return ans;
  }
};
