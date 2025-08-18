class Solution {
public:
  int titleToNumber(string columnTitle) {
    long long ans = 0;
    long long base = 1;
    for (int i = 0; i < columnTitle.size(); i++) {
      int d = columnTitle[columnTitle.size() - 1 - i] - 'A';
      ans += base * (d + 1);
      base *= 26;
    }

    return ans;
  }
};
