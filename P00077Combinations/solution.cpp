class Solution {
private:
  void comb(int s, int n, int k, vector<int> &current,
            vector<vector<int>> &result) {
    if (current.size() == k) {
      result.push_back(vector<int>(current.begin(), current.end()));
      return;
    }

    for (int i = s; i <= n; i++) {
      current.push_back(i);
      comb(i + 1, n, k, current, result);
      current.erase(current.end());
    }
  }

public:
  vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> r;
    vector<int> c;
    comb(1, n, k, c, r);
    return r;
  }
};
