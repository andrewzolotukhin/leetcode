class Solution {
private:
  vector<pair<int, int>> serves{{100, 0}, {75, 25}, {50, 50}, {25, 75}};
  vector<vector<double>> t;
  double simulate(int l, int r) {
    if (l <= 0 && r <= 0)
      return 0.5;

    if (l <= 0)
      return 1.0;
    if (r <= 0)
      return 0.0;

    if (t[l][r] != -1.0)
      return t[l][r];

    double probability = 0.0;

    for (auto &p : serves) {

      double l_serve = p.first;
      double r_serve = p.second;

      probability += 0.25 * simulate(l - l_serve, r - r_serve);
    }

    return t[l][r] = probability;
  }

public:
  double soupServings(int n) {
    if (n >= 5000)
      return 1.0;

    t.resize(n + 1, vector<double>(n + 1, -1.0));

    return simulate(n, n);
  }
};
