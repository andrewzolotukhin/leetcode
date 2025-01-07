#include <bits/stdc++.h>
#include <string>
using namespace std;

class Solution {
public:
  string solve(vector<int> &elements, int k) {
    if (elements.size() == 1) {
      return to_string(elements[0]);
    }

    if (elements.size() == 2) {
      return (k < 2) ? (to_string(elements[0]) + to_string(elements[1]))
                     : (to_string(elements[1]) + to_string(elements[0]));
    }

    int factorial = 1;
    for (int i = 2; i < elements.size(); i++) {
      factorial *= i;
    }

    if (k > factorial) {
      if (k % factorial == 0) {
        auto currIndex = k / factorial - 1;
        auto curr = elements[currIndex];
        elements.erase(elements.begin() + currIndex);
        return to_string(curr) + solve(elements, factorial);
      }
      auto currIndex = k / factorial;
      auto curr = elements[currIndex];
      elements.erase(elements.begin() + currIndex);
      return to_string(curr) + solve(elements, k % factorial);
    } else {
      auto curr = elements[0];
      elements.erase(elements.begin());
      return to_string(curr) + solve(elements, k);
    }
  }

  string getPermutation(int n, int k) {
    vector<int> elements;
    for (int i = 1; i <= n; i++) {
      elements.push_back(i);
    }

    return solve(elements, k);
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  int n, k;
  cin >> n >> k;

  Solution s;
  cout << s.getPermutation(n, k) << '\n';
}
