class Solution {
private:
  void solve(vector<array<int, 3>> &garbage, vector<int> &travel, int &ans,
             int type) {
    int collected = 0;
    int curr = 0;
    for (int i = 0; i < garbage.size(); i++) {
      if (garbage[i][type]) {
        collected += curr + garbage[i][type];
        curr = 0;
      }
      if (i < garbage.size() - 1) {
        curr += travel[i];
      }
    }

    ans += collected;
  }

public:
  int garbageCollection(vector<string> &garbage, vector<int> &travel) {
    int ans = 0;
    vector<array<int, 3>> gb;
    for (int i = 0; i < garbage.size(); i++) {
      int g = 0, p = 0, m = 0;
      for (int j = 0; j < garbage[i].size(); j++) {
        if (garbage[i][j] == 'G')
          g++;
        if (garbage[i][j] == 'P')
          p++;
        if (garbage[i][j] == 'M')
          m++;
      }
      gb.push_back({g, p, m});
    }

    solve(gb, travel, ans, 0);
    solve(gb, travel, ans, 1);
    solve(gb, travel, ans, 2);

    return ans;
  }
};
