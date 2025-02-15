#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void setZeroes(vector<vector<int>> &matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    vector<bool> rows(n, false), cols(m, false);

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (matrix[i][j] == 0) {
          rows[i] = true;
          cols[j] = true;
        }
      }
    }

    for (int i = 0; i < rows.size(); i++) {
      if (!rows[i])
        continue;
      for (int j = 0; j < m; j++) {
        matrix[i][j] = 0;
      }
    }

    for (int j = 0; j < cols.size(); j++) {
      if (!cols[j])
        continue;
      for (int i = 0; i < n; i++) {
        matrix[i][j] = 0;
      }
    }
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  int n, m;
  cin >> n >> m;

  vector<vector<int>> matrix(n, vector<int>(m));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> matrix[i][j];
    }
  }

  Solution().setZeroes(matrix);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
}
