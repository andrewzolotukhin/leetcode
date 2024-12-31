#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int longestValidParentheses(string s) {
    stack<int> stack;
    stack.push(-1);
    int maxLen = 0;

    for (int i = 0; i < s.size(); i++) {
      auto last = stack.top();
      if (last != -1 && s[i] == ')' && s[last] == '(') {
        stack.pop();
        maxLen = max(maxLen, i - stack.top());
      } else {
        stack.push(i);
      }
    }

    return maxLen;
  }
};

int main() {
  Solution sol;
  string s;

  cin >> s;

  if (s.size() == 0) {
    cout << 0 << endl;
    return 0;
  }

  cout << sol.longestValidParentheses(s) << endl;

  return 0;
}
