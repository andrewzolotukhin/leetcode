#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    int n = matrix.size();
    int m = matrix[0].size();
    if (n == m && n == 1) {
      return matrix[0][0] == target;
    }

    int rowIndex = -1;

    if (n == 1) {
      rowIndex = 0;
    } else {
      if (matrix[0][0] > target) {
        return false;
      }
      int left = 0;
      int right = n - 1;

      while (left <= right) {
        int mid = left + (right - left) / 2;

        if (matrix[mid][0] == target) {
          return true;
        } else if (matrix[mid][0] < target) {
          rowIndex = mid;
          left = mid + 1;
        } else {
          right = mid - 1;
        }
      }
    }

    if (m == 1) {
      return matrix[rowIndex][0] == target;
    } else {
      if (matrix[rowIndex][0] > target) {
        return false;
      }
      int left = 0;
      int right = m - 1;

      while (left <= right) {
        int mid = left + (right - left) / 2;

        if (matrix[rowIndex][mid] == target) {
          return true;
        } else if (matrix[rowIndex][mid] < target) {
          left = mid + 1;
        } else {
          right = mid - 1;
        }
      }
    }

    return false;
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  int n, m, target;

  cin >> n >> m >> target;

  vector<vector<int>> matrix(n, vector<int>(m));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> matrix[i][j];
    }
  }

  cout << (Solution().searchMatrix(matrix, target) ? "yes" : "no") << endl;
}
