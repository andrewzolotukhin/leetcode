class Solution {
public:
  string largestGoodInteger(string num) {
    char ans = 0;
    for (int i = 0; i <= num.size() - 2; i++) {
      if (num[i] == num[i + 1] && num[i] == num[i + 2] && num[i] > ans) {
        ans = num[i];
      }
    }
    if (ans == 0)
      return "";
    return string(3, ans);
  }
};
