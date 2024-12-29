#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<int>> insert(vector<vector<int>> &intervals,
                             vector<int> &newInterval) {
    vector<vector<int>> result;

    auto i = 0;

    if (intervals.size() == 0) {
      return {newInterval};
    }

    bool noMerge = false;

    if (newInterval[1] < intervals[0][0]) {
      int t1 = newInterval[0];
      int t2 = newInterval[1];
      newInterval[0] = intervals[0][0];
      intervals[0][0] = t1;

      newInterval[1] = intervals[0][1];
      intervals[0][1] = t2;
      noMerge = true;
    }

    while (i < intervals.size() && (intervals[i][1] < newInterval[0])) {
      result.emplace_back(intervals[i]);
      i++;
    }

    if (intervals.size() == i) {
      result.emplace_back(newInterval);
      return result;
    }

    auto isOverlapping = [&](int as, int ae, int bs, int be) {
      return (ae >= bs);
    };

    if (!noMerge && isOverlapping(newInterval[0], newInterval[1],
                                  intervals[i][0], intervals[i][1])) {

      int ns = min(intervals[i][0], newInterval[0]);
      int ne = max(intervals[i][1], newInterval[1]);
      i++;
      while (i < intervals.size() &&
             isOverlapping(ns, ne, intervals[i][0], intervals[i][1])) {
        ne = max(ne, intervals[i][1]);
        i++;
      }

      result.push_back({ns, ne});

      if (i == intervals.size()) {
        return result;
      }
    } else {
      result.push_back(newInterval);
    }

    while (i < intervals.size()) {
      result.emplace_back(intervals[i]);
      i++;
    }

    return result;
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  int n, ns, ne;

  cin >> n >> ns >> ne;

  vector<vector<int>> intervals;
  vector<int> newInterval = {ns, ne};

  while (n--) {
    int a, b;
    cin >> a >> b;
    intervals.push_back({a, b});
  }

  Solution s;

  auto sol = s.insert(intervals, newInterval);

  for (auto i : sol) {
    cout << i[0] << " " << i[1] << '\n';
  }
}
