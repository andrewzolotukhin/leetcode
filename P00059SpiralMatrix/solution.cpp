#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<int>> generateMatrix(int n) {
    auto isInside = [&](int x, int y) {
      return (x >= 0 && x < n && y >= 0 && y < n);
    };

    int posX = 0, posY = 0;
    auto result = vector<vector<int>>(n, vector<int>(n, 0));
    vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    auto dir = 0;
    auto cell = 0;

    do {
      result[posX][posY] = ++cell;

      int newPosX = posX + directions[dir].first;
      int newPosY = posY + directions[dir].second;

      if (!isInside(newPosX, newPosY) || result[newPosX][newPosY]) {
        dir = (dir + 1) % directions.size();
        newPosX = posX + directions[dir].first;
        newPosY = posY + directions[dir].second;
      }

      posX = newPosX;
      posY = newPosY;
    } while (cell < n * n);

    return result;
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  for (auto i = 1; i < 20; i++) {
    auto solution = Solution().generateMatrix(i);

    for (auto row : solution) {
      for (auto cell : row) {
        cout << cell << "   ";
      }
      cout << endl;
    }
    cout << endl;
  }
}
