class Solution {
public:
  double dist(int x1, int y1, int x2, int y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
  }
  double largestTriangleArea(vector<vector<int>> &points) {
    double ans = 0;
    for (int i = 0; i < points.size(); i++) {
      for (int j = i + 1; j < points.size(); j++) {
        for (int k = j + 1; k < points.size(); k++) {
          double a =
              dist(points[i][0], points[i][1], points[j][0], points[j][1]);
          double b =
              dist(points[i][0], points[i][1], points[k][0], points[k][1]);
          double c =
              dist(points[k][0], points[k][1], points[j][0], points[j][1]);
          double p = (a + b + c) / 2;
          ans = max(ans, sqrt(p * (p - a) * (p - b) * (p - c)));
        }
      }
    }
    return ans;
  }
};
