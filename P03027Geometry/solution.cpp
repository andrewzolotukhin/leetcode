class Solution {
public:
  int numberOfPairs(vector<vector<int>> &points) {
    auto comp = [&](vector<int> &a, vector<int> &b) {
      if (a[0] == b[0]) {
        return a[1] < b[1];
      }
      return a[0] > b[0];
    };

    sort(points.begin(), points.end(), comp);
    int ans = 0;
    for (int i = 0; i < points.size() - 1; i++) {
      int y = INT_MAX;
      for (int j = i + 1; j < points.size(); j++) {
        if (points[i][1] <= points[j][1] && points[j][1] < y) {
          ans++;
          y = points[j][1];
        }
      }
    }

    return ans;
  }
};
