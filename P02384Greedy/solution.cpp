class Solution {
public:
  string largestPalindromic(string num) {
    vector<int> freq(10, 0);

    for (auto c : num) {
      freq[c - '0']++;
    }

    string h = "";
    bool hasMid = false;
    char mid = 0;

    for (int i = 9; i >= 0; i--) {
      if (freq[i] > 0) {
        if (freq[i] / 2 > 0) {
          if (!(i == 0 && h.size() == 0)) {
            h += string(freq[i] / 2, '0' + i);
          }
        }
        if (!hasMid && freq[i] % 2) {
          hasMid = true;
          mid = '0' + i;
        }
      }
    }

    string ans = h;
    if (hasMid) {
      ans += mid;
    }
    reverse(h.begin(), h.end());

    ans += h;

    if (ans == "")
      ans = "0";

    return ans;
  }
};
