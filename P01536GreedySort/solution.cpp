class Solution {
public:
  int minSwaps(vector<vector<int>> &grid) {
    int n = grid.size(), ans = 0;

    vector<int> r;
    for (auto row : grid) {
      int c = 0;
      for (int j = n - 1; j >= 0 && row[j] == 0; j--) {
        c++;
      }
      r.push_back(c);
    }

    for (int i = 0, mtz = n - 1; i < n; i++, mtz--) {
      int sri = i;
      while (sri < n && r[sri] < mtz)
        sri++;
      if (sri == n)
        return -1;

      while (sri > i) {
        swap(r[sri], r[sri - 1]);
        sri--;
        ans++;
      }
    }

    return ans;
  }
};
