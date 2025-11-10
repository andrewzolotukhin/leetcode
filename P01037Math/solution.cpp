class Solution {
public:
  bool isBoomerang(vector<vector<int>> &points) {
    unordered_set<int> d;
    for (auto &p : points) {
      d.insert((p[0] << 10) | p[1]);
    }
    if (d.size() != 3)
      return false;

    int dx1 = points[0][0] - points[1][0];
    int dy1 = points[0][1] - points[1][1];
    int dx2 = points[1][0] - points[2][0];
    int dy2 = points[1][1] - points[2][1];

    return dx1 * dy2 != dx2 * dy1;
  }
};
