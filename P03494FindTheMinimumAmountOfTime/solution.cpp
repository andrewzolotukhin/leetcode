#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  long long minTime(vector<int> &skill, vector<int> &mana) {
    int n = skill.size();
    int m = mana.size();

    vector<long long> prev(n + 1);

    for (int j = 0; j < m; j++) {
      for (int i = 0; i < n; i++) {
        prev[i + 1] = max(prev[i], prev[i + 1]) + mana[j] * skill[i];
      }
      for (int i = n - 1; i >= 0; i--) {
        prev[i] = prev[i + 1] - mana[j] * skill[i];
      }
    }

    return prev[n];
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  int n, m;
  cin >> n;
  vector<int> skill(n);
  for (auto &s : skill) {
    cin >> s;
  }

  cin >> m;
  vector<int> mana(m);
  for (auto &s : mana) {
    cin >> s;
  }

  cout << Solution().minTime(skill, mana) << '\n';
}
