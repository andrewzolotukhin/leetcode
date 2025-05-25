class Solution {
public:
  int longestPalindrome(vector<string> &words) {
    int cnt[26][26];
    memset(&cnt, 0, sizeof(cnt));

    for (int i = 0; i < words.size(); i++) {
      cnt[(int)(words[i][0] - 'a')][(int)(words[i][1] - 'a')]++;
    }

    int ans = 0;
    int maxMid = 0;

    for (int i = 0; i < 26; i++) {
      for (int j = 0; j < 26; j++) {
        if (i == j) {
          if (cnt[i][i] > 1) {
            if (cnt[i][i] % 2 == 1) {
              ans += 2 * (cnt[i][i] - 1);
              maxMid = 1;
            } else {
              ans += 2 * cnt[i][i];
            }
          } else if (cnt[i][i] == 1) {
            maxMid = 1;
          }
        } else {
          ans += ((cnt[i][j] < cnt[j][i]) ? cnt[i][j] : cnt[j][i]) * 2;
        }
      }
    }

    return ans + 2 * maxMid;
  }
};
