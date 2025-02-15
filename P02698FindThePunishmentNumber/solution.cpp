#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  bool isMagical(string &s, int num) {

    if (s == "" && num == 0) {
      return true;
    }

    if (num < 0)
      return false;

    for (int i = 0; i < s.size(); i++) {
      auto left = s.substr(0, i + 1);
      auto right = s.substr(i + 1);

      auto leftNumber = stoi(left);

      if (isMagical(right, num - leftNumber)) {
        return true;
      }
    }

    return false;
  }

public:
  int punishmentNumber(int n) {
    int sum = 0;

    for (int i = 1; i <= n; i++) {
      int square = i * i;
      string squareStr = to_string(square);
      if (isMagical(squareStr, i)) {
        sum += i * i;
      }
    }

    return sum;
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  int n;
  cin >> n;
  cout << Solution().punishmentNumber(n) << '\n';
}
