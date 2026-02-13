class Solution {
public:
  void solve(string &s, char a, char b, int &ans) {
    int n = s.size();

    int sum = 0;
    unordered_map<int, int> m;
    m[0] = -1;

    for (int i = 0; i < n; i++) {
      if (s[i] == a) {
        sum++;
      } else if (s[i] == b) {
        sum--;
      } else {
        m.clear();
        m[0] = i;
        sum = 0;
        continue;
      }

      if (m.find(sum) != m.end()) {
        ans = max(ans, i - m[sum]);
      } else {
        m[sum] = i;
      }
    }
  }

  int longestBalanced(string s) {
    if (s.size() == 1)
      return 1;
    int ans = 1, c = 1;
    for (int i = 1; i < s.size(); i++) {
      if (s[i] == s[i - 1]) {
        c++;
      } else {
        c = 1;
      }
      ans = max(ans, c);
    }

    solve(s, 'a', 'b', ans);
    solve(s, 'b', 'c', ans);
    solve(s, 'a', 'c', ans);

    vector<int> freq(3, 0);
    map<pair<int, int>, int> m;
    m[{0, 0}] = -1;

    for (int i = 0; i < s.size(); i++) {
      freq[s[i] - 'a']++;
      auto cab = freq[0] - freq[1];
      auto cac = freq[0] - freq[2];
      if (m.find({cab, cac}) != m.end()) {
        ans = max(ans, i - m[{cab, cac}]);
      } else {
        m[{cab, cac}] = i;
      }
    }

    return ans;
  }
};
