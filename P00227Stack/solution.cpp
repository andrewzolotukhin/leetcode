class Solution {
public:
  int calculate(string s) {
    stack<int> ops;
    int n = s.size();
    int num = 0;
    char op = '+';

    for (int i = 0; i < n; i++) {
      if (isdigit(s[i])) {
        num = (num * 10) + (s[i] - '0');
      }
      if (!isdigit(s[i]) && !iswspace(s[i]) || i == n - 1) {
        if (op == '-') {
          ops.push(-num);
        } else if (op == '+') {
          ops.push(num);
        } else if (op == '*') {
          int t = ops.top();
          ops.pop();
          ops.push(t * num);
        } else {
          int t = ops.top();
          ops.pop();
          ops.push(t / num);
        }
        op = s[i];
        num = 0;
      }
    }

    int ans = 0;
    while (!ops.empty()) {
      ans += ops.top();
      ops.pop();
    }

    return ans;
  }
};
