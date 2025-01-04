#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int solve(int day, vector<bool> &daysWithTravel, vector<int> &dp,
            vector<int> &costs) {
    if (day > dp.size() - 1) {
      return 0;
    }
    if (dp[day] != -1) {
      return dp[day];
    }

    int result = 0;

    if (daysWithTravel[day]) {
      result = min(min(costs[0] + solve(day + 1, daysWithTravel, dp, costs),
                       costs[1] + solve(day + 7, daysWithTravel, dp, costs)),
                   costs[2] + solve(day + 30, daysWithTravel, dp, costs));
    } else {
      result = solve(day + 1, daysWithTravel, dp, costs);
    }

    dp[day] = result;
    return result;
  }

  int mincostTickets(vector<int> &days, vector<int> &costs) {
    vector<bool> daysWithTravel(365, false);
    vector<int> dp(366, -1);
    for (auto day : days) {
      daysWithTravel[day - 1] = true;
    }

    return solve(0, daysWithTravel, dp, costs);
  }
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
