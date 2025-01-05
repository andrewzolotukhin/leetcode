#include <bits/stdc++.h>
#include <climits>
using namespace std;

class Solution {
public:
  string shiftingLetters(string s, vector<vector<int>> &shifts) {

    vector<int> diff(s.size() + 1, 0);

    for (int i = 0; i < shifts.size(); i++) {
      int change = (shifts[i][2] == 1) ? 1 : -1;
      diff[shifts[i][0]] += change;
      diff[shifts[i][1] + 1] -= change;
    }

    string result = s;
    int currDiff = 0;

    for (int i = 0; i < s.size(); i++) {
      currDiff += diff[i];
      result[i] = 'a' + ((s[i] - 'a' + currDiff % 26 + 26) % 26);
    }
    return result;
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  int n;
  string s;
  cin >> s;
  cin >> n;

  vector<vector<int>> shifts;

  for (int i = 0; i < n; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    shifts.push_back({
        a,
        b,
        c,
    });
  }

  Solution sol;
  cout << sol.shiftingLetters(s, shifts) << '\n';
}
