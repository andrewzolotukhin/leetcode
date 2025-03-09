#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<int>> sortMatrix(vector<vector<int>> &grid) {
    int n = grid.size();

    if (n == 1)
      return grid;

    for (int diag = 0; diag < n; diag++) {
      // diag starts in `diag` row and 0 column
      // and has n - diag elements
      // sort ascending
      int diagLen = n - diag;
      vector<int> elements;
      for (int i = 0; i < diagLen; i++) {
        elements.push_back(grid[diag + i][i]);
      }
      sort(elements.begin(), elements.end());
      for (int i = 0; i < diagLen; i++) {
        grid[diag + i][i] = elements[diagLen - 1 - i];
      }
    }

    for (int diag = 1; diag < n; diag++) {
      // diag starts in `0` row and `diag` column
      // and has n - diag elements
      // sort descending
      int diagLen = n - diag;
      vector<int> elements;
      for (int i = 0; i < diagLen; i++) {
        elements.push_back(grid[i][diag + i]);
      }
      sort(elements.begin(), elements.end());
      for (int i = 0; i < diagLen; i++) {
        grid[i][diag + i] = elements[i];
      }
    }

    return grid;
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  int n;

  cin >> n;

  vector<vector<int>> grid(n, vector<int>(n));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> grid[i][j];
    }
  }

  auto result = Solution().sortMatrix(grid);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << result[i][j] << " ";
    }
    cout << endl;
  }
}
