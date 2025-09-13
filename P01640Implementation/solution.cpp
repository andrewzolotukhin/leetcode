class Solution {
public:
  bool canFormArray(vector<int> &arr, vector<vector<int>> &pieces) {
    int n = arr.size(), m = pieces.size();
    vector<bool> used(m, false);
    unordered_set<int> s;
    for (auto a : arr)
      s.insert(a);
    for (auto p : pieces) {
      for (auto v : p)
        if (s.count(v) == 0)
          return false;
    }

    int i = 0;
    while (i < n) {
      for (int j = 0; j < m; j++) {
        if (used[j])
          continue;
        int k = 0;
        while (k < pieces[j].size() && pieces[j][k] == arr[i]) {
          k++;
          i++;
        }
        if (k == 0)
          continue;
        if (k != pieces[j].size())
          return false;
        used[j] = true;
        break;
      }
      i++;
    }

    return true;
  }
};
