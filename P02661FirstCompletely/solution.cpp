#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int firstCompleteIndex(vector<int> &arr, vector<vector<int>> &mat) {
    int n = mat.size();
    int m = mat[0].size();
    vector<int> rows(n, m);
    vector<int> cols(m, n);
    vector<pair<int, int>> cords(n * m);

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cords[mat[i][j] - 1] = {i, j};
      }
    }

    for (int i = 0; i < arr.size(); i++) {
      auto [r, c] = cords[arr[i] - 1];

      rows[r]--;
      cols[c]--;
      if (rows[r] <= 0 || cols[c] <= 0)
        return i;
    }

    assert(false);
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  int l;
  vector<int> arr;
  cin >> l;
  while (l--) {
    int x;
    cin >> x;
    arr.push_back(x);
  }

  int n, m;
  cin >> n >> m;

  vector<vector<int>> mat(n, vector<int>());

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int x;
      cin >> x;
      mat[i].push_back(x);
    }
  }

  Solution solution;

  cout << solution.firstCompleteIndex(arr, mat) << endl;
}
