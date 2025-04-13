class Solution {
public:
  long long maximumSubsequenceCount(string text, string pattern) {
    long long ans1 = 0, ans2 = 0;

    int fc = 0, sc = 0, n = text.size();
    // vector<int> ff(n, -1), sf(n, n);
    for (int i = 0; i < n; i++) {
      // ff[i] = fc;
      if (text[i] == pattern[1]) {
        ans1 += fc;
      }
      if (text[i] == pattern[0]) {
        fc++;
      }
    }
    ans1 += fc;

    if (pattern[0] == pattern[1]) {
      ans2 = ans1;
    } else {
      for (int i = n - 1; i >= 0; i--) {
        if (text[i] == pattern[0]) {
          ans2 += sc;
        }
        if (text[i] == pattern[1]) {
          sc++;
        }
      }
      ans2 += sc;
    }

    return max(ans1, ans2);
  }
};
