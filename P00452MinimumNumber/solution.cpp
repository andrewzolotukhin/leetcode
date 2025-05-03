class Solution {
public:
  int findMinArrowShots(vector<vector<int>> &points) {
    sort(points.begin(), points.end());

    int ans = points.size();

    vector<int> prev = points[0];

    for (int i = 1; i < points.size(); i++) {
      auto current = points[i];
      if (current[0] <= prev[1]) {
        ans--;
        prev = {current[0], prev[1] < current[1] ? prev[1] : current[1]};
      } else {
        prev = current;
      }
    }
    return ans;
  }
};
