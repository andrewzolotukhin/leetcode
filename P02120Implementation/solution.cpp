class Solution {
public:
  vector<int> executeInstructions(int n, vector<int> &startPos, string s) {
    auto isInside = [&](int x, int y) {
      return x >= 0 && x < n && y >= 0 && y < n;
    };
    unordered_map<char, pair<int, int>> dirs;
    dirs['L'] = {0, -1};
    dirs['R'] = {0, 1};
    dirs['U'] = {-1, 0};
    dirs['D'] = {1, 0};

    vector<int> ans;

    for (int i = 0; i < s.size(); i++) {
      int x = startPos[0], y = startPos[1];
      int r = 0;
      for (int j = i; j < s.size(); j++) {
        int nx = x + dirs[s[j]].first;
        int ny = y + dirs[s[j]].second;
        if (!isInside(nx, ny))
          break;
        r++;
        x = nx;
        y = ny;
      }
      ans.push_back(r);
    }
    return ans;
  }
};
