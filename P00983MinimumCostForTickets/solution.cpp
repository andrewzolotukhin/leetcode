#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int mincostTickets(vector<int> &days, vector<int> &costs) {}
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  vector<int> days, costs;

  int n;
  cin >> n;

  for (int i = 0; i < 3; i++) {
    int a;
    cin >> a;
    costs.push_back(a);
  }

  while (n--) {
    int a;
    cin >> a;
    days.push_back(a);
  }

  Solution s;

  cout << s.mincostTickets(days, costs);
}
