class Solution {
public:
  string convertToTitle(int columnNumber) {
    string ans = "";
    while (columnNumber) {
      columnNumber--;
      ans += (columnNumber % 26) + 'A';
      columnNumber /= 26;
    }
    if (ans == "")
      return "A";
    reverse(ans.begin(), ans.end());
    return ans;
  }
};
