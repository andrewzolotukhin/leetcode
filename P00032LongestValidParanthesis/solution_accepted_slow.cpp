#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int find(string &s, int start, vector<int> &memo) {
    if (start >= s.size() - 1)
      return 0;

    if (memo[start] != -1) {
      return memo[start];
    }

    if (s[start] != '(') {
      memo[start] = 0;
      return 0;
    }

    if (s[start + 1] == ')') {
      memo[start] = 2;
      return 2;
    }

    auto nextChar = start + 1;
    auto totalInner = 0;

    while (true) {
      auto inner = find(s, nextChar, memo);

      if (inner == 0) {
        break;
      }
      totalInner += inner;
      nextChar += inner;
    }

    if (start + totalInner + 1 >= s.size()) {
      memo[start] = 0;
      return 0;
    }

    if (s[start + totalInner + 1] == ')') {
      memo[start] = totalInner + 2;
      return totalInner + 2;
    }

    return 0;
  }

  int longestValidParentheses(string s) {
    int currentIndex = 0;
    int max = 0;
    int currentGroup = 0;
    vector<int> memo(s.size(), -1);

    while (currentIndex < s.size()) {
      auto result = find(s, currentIndex, memo);
      if (result == 0) {
        currentGroup = 0;
        currentIndex++;
      } else {
        currentGroup += result;
        currentIndex += result;
        if (currentGroup > max) {
          max = currentGroup;
        }
      }
    }

    return max;
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
