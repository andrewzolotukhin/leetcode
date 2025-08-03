class Solution {
private:
  bool isValid(string s, int k) {
    long long total = (long long)(s.size() + 1) * (long long)(s.size()) / 2;

    int i = 0;

    while (i < s.size()) {
      int c = 0;
      while (i < s.size() && s[i] != '*') {
        i++;
        c++;
      }
      total -= ((long long)(c + 1)) * c / 2;
      while (i < s.size() && s[i] == '*')
        i++;
    }

    return total >= k;
  }

public:
  int minTime(string s, vector<int> &order, int k) {
    int l = 0, r = s.size() - 1;
    int ans = INT_MAX;
    while (l <= r) {
      int mid = (l + r) / 2;

      string v = s;
      for (int i = 0; i <= mid; i++) {
        v[order[i]] = '*';
      }

      if (isValid(v, k)) {
        ans = min(ans, mid);
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
    return (ans == INT_MAX) ? -1 : ans;
  }
};
©leetcode
