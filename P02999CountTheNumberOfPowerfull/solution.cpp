class Solution {
private:
  long long combinate(string &n, string &s, int limit) {
    if (s.size() > n.size())
      return 0;
    if (s.size() == n.size()) {
      return n >= s ? 1 : 0;
    }

    string su = n.substr(n.size() - s.size(), s.size());
    int mlen = n.size() - su.size();

    long long ans = 0LL;

    for (int i = 0; i < mlen; i++) {
      int c = n[i] - '0';
      if (limit < c) {
        ans += (long long)pow(limit + 1, mlen - i);
        return ans;
      }

      ans += (long long)c * (long long)pow(limit + 1, mlen - 1 - i);
    }
    if (su >= s) {
      ans++;
    }

    return ans;
  }

public:
  long long numberOfPowerfulInt(long long start, long long finish, int limit,
                                string s) {
    long long ans = 0;

    string sstart = to_string(start - 1);
    string sfinish = to_string(finish);

    return combinate(sfinish, s, limit) - combinate(sstart, s, limit);
  }
};
