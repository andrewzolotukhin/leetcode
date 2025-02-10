#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string clearDigits(string s) {
    stack<char> nonDigits;
    int n = s.size();
    vector<bool> shouldRemove(n, false);

    auto isDigit = [](char c) { return c >= '0' && c <= '9'; };

    for (int i = 0; i < n; i++) {
      if (isDigit(s[i])) {
        shouldRemove[i] = true;
        if (!nonDigits.empty()) {
          int prevDigitIndex = nonDigits.top();
          nonDigits.pop();
          shouldRemove[prevDigitIndex] = true;
        }
      } else {
        nonDigits.push(i);
      }
    }

    string result = "";

    for (int i = 0; i < n; i++) {
      if (!shouldRemove[i]) {
        result += s[i];
      }
    }

    return result;
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  string s;
  cin >> s;

  cout << '"' << Solution().clearDigits(s) << '"' << endl;
}
