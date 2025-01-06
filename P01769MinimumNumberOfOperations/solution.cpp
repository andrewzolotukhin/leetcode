#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;

class Solution {
public:
  vector<int> minOperations(string boxes) {
    vector<int> result(boxes.size(), 0);
    for (int i = 0; i < boxes.size(); i++) {
      for (int j = 0; j < boxes.size(); j++) {
        if (i == j || boxes[j] == '0')
          continue;

        result[i] += abs(i - j);
      }
    }

    return result;
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  Solution sol;
  string s;
  cin >> s;

  auto result = sol.minOperations(s);

  for (int b : result) {
    cout << b << '\n';
  }
}
