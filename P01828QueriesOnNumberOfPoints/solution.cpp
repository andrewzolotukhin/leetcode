class Solution {
public:
  vector<int> countPoints(vector<vector<int>> &points,
                          vector<vector<int>> &queries) {
    int n = points.size();
    vector<pair<int, int>> xs(n), ys(n);

    for (int i = 0; i < n; i++) {
      xs[i] = {points[i][0], i};
      ys[i] = {points[i][1], i};
    }

    sort(xs.begin(), xs.end());
    sort(ys.begin(), ys.end());

    auto comp = [&](pair<int, int> &a, pair<int, int> &b) -> bool {
      return a.first > b.first;
    };

    vector<int> ans;
    for (auto q : queries) {
      int x = q[0], y = q[1], r = q[2];

      set<int> cands;
      pair<int, int> xpair = {x - r, -1};
      pair<int, int> ypair = {y - r, -1};
      int cx = lower_bound(xs.begin(), xs.end(), xpair) - xs.begin();
      int cy = lower_bound(ys.begin(), ys.end(), ypair) - ys.begin();

      while (cx < xs.size() && xs[cx].first >= x - r && xs[cx].first <= x + r) {
        cands.insert(xs[cx].second);
        cx++;
      }
      while (cy < ys.size() && ys[cy].first >= y - r && ys[cy].first <= y + r) {
        if (cands.count(ys[cy].second) == 0) {
          cy++;
          continue;
        }
        cands.insert(ys[cy].second);
        cy++;
      }

      int a = 0;
      // cout << "x: " << x << "; y: " << y << "\n";
      for (auto pi : cands) {
        // cout << pi << '\n';
        // cout << " - " << r*r << " <=> " <<
        // (points[pi][0]-x)*(points[pi][0]-x)+(points[pi][1]-y)*(points[pi][1]-y)
        // << '\n';
        if (r * r >= (points[pi][0] - x) * (points[pi][0] - x) +
                         (points[pi][1] - y) * (points[pi][1] - y)) {
          a++;
        }
      }
      // cout << '\n';
      ans.push_back(a);
    }

    return ans;
  }
};
