double e = 1e-5;
class Solution {
public:
  double minAreaFreeRect(vector<vector<int>> &points) {
    vector<vector<int>> a = {};
    double ans = DBL_MAX;
    int n = points.size();

    map<long long, map<pair<int, int>, vector<pair<int, int>>>> m;

    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        int x1 = points[i][0], y1 = points[i][1];
        int x2 = points[j][0], y2 = points[j][1];

        int midX = x1 + x2;
        int midY = y1 + y2;
        int dx = x1 - x2;
        int dy = y1 - y2;
        long long dist = (long long)dx * dx + (long long)dy * dy;

        m[dist][{midX, midY}].push_back({x1, y1});
      }
    }

    for (auto &[dist, midpoints] : m) {
      for (auto &[mid, point_list] : midpoints) {
        long long midX = mid.first;
        long long midY = mid.second;

        for (int i = 0; i < point_list.size(); i++) {
          for (int j = i + 1; j < point_list.size(); j++) {
            int x1 = point_list[i].first, y1 = point_list[i].second;
            int x2 = point_list[j].first, y2 = point_list[j].second;

            long long vx1 = x2 - x1, vy1 = y2 - y1;
            long long vx2 = (midX - x2) - x1, vy2 = (midY - y2) - y1;

            if (vx1 * vx2 + vy1 * vy2 != 0)
              continue;

            double side1 = sqrt(vx1 * vx1 + vy1 * vy1);
            double side2 = sqrt(vx2 * vx2 + vy2 * vy2);
            double area = side1 * side2;

            ans = min(ans, area);
          }
        }
      }
    }

    if (ans == DBL_MAX)
      return 0;
    return ans;
  }
};
