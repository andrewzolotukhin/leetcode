class Solution {
public:
  int numberOfPairs(vector<vector<int>> &points) {
    auto compare = [&](vector<int> &a, vector<int> &b) {
      return (a[0] == b[0]) ? a[1] < b[1] : a[0] > b[0];
    };

    int ans = 0;
    sort(points.begin(), points.end(), compare);

    for (int i = 0; i < points.size() - 1; i++) {
      int y = INT_MAX;
      for (int j = i + 1; j < points.size(); j++) {
        if (points[j][1] >= points[i][1] && y > points[j][1]) {
          ans++;
          y = points[j][1];
        }
      }
    }

    return ans;
  }
};
