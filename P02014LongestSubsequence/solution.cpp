class Solution {
private:
  bool isGood(string &s, string &x, int k) {
    int p = 0, m = 0;
    int n = s.size(), ms = x.size();

    for (char c : s) {
      if (c == x[p]) {
        p++;
        if (p == ms) {
          p = 0;
          m++;
          if (m == k) {
            return true;
          }
        }
      }
    }
    return false;
  }

public:
  string longestSubsequenceRepeatedK(string s, int k) {
    vector<int> freq(26);
    for (int i = 0; i < s.size(); i++) {
      freq[s[i] - 'a']++;
    }

    vector<int> good;
    for (int i = 25; i >= 0; i--) {
      if (freq[i] >= k)
        good.push_back(i);
    }

    queue<string> q;

    for (auto g : good) {
      q.push(string(1, 'a' + g));
    }

    string ans = "";

    while (!q.empty()) {
      auto curr = q.front();
      q.pop();
      if (curr.size() > ans.size()) {
        ans = curr;
      }

      for (int g : good) {
        string x = curr + string(1, 'a' + g);

        if (isGood(s, x, k)) {
          q.push(x);
        }
      }
    }

    return ans;
  }
};
