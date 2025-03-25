class Solution {
private:
  bool canCut(map<int, pair<int, int>> &coords) {
    int sections = 0;
    int curr = 0;
    int prevCut = -1;
    for (auto [c, v] : coords) {
      if (v.second > 0 && (curr - v.second == 0)) {
        sections++;
      }

      if (sections > 2)
        return true;

      curr += v.first - v.second;
    }
    return sections > 2;
  }

public:
  bool checkValidCuts(int n, vector<vector<int>> &rectangles) {
    map<int, pair<int, int>> xs, ys;

    for (int i = 0; i < rectangles.size(); i++) {
      int x1 = rectangles[i][0];
      int y1 = rectangles[i][1];
      int x2 = rectangles[i][2];
      int y2 = rectangles[i][3];
      xs[x1].first++;
      xs[x2].second++;
      ys[y1].first++;
      ys[y2].second++;
    }

    return canCut(xs) || canCut(ys);
  }
};
