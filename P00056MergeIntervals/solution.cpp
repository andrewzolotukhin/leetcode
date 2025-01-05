#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>> &intervals) {
    vector<vector<int>> result;
    if (intervals.size() == 0) {
      return {};
    };

    sort(intervals.begin(), intervals.end(),
         [&](vector<int> &a, vector<int> &b) {
           if (a[0] == b[0])
             return a[1] > b[1];
           return a[0] < b[0];
         });

    auto current = intervals[0];
    auto i = 1;

    while (i < intervals.size()) {
      if (current[1] >= intervals[i][0]) {
        current = {current[0], max(intervals[i][1], current[1])};
      } else {
        result.push_back(current);
        current = intervals[i];
      }
      i++;
    }

    result.push_back(current);

    return result;
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  int n;
  cin >> n;
  vector<vector<int>> intervals(n, vector<int>());

  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    intervals[i].push_back(a);
    intervals[i].push_back(b);
  }

  Solution s;
  auto result = s.merge(intervals);

  for (auto interval : result) {
    cout << interval[0] << " " << interval[1] << '\n';
  }
}
