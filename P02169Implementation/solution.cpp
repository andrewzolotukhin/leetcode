class Solution {
public:
  int countOperations(int num1, int num2) {
    int mn = min(num1, num2);
    int mx = max(num1, num2);

    int ans = 0;
    while (mn && mx) {
      ans += mx / mn;
      int v1 = mx % mn;
      int v2 = mn;
      mn = min(v1, v2);
      mx = max(v1, v2);
    }
    return ans;
  }
};
