#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  bool search(int n, int index, vector<bool> &isUsed, vector<int> &result) {
    if (index == result.size()) {
      return true;
    }

    if (result[index] != 0) {
      return search(n, index + 1, isUsed, result);
    }

    for (int i = n; i >= 1; i--) {
      if (isUsed[i]) {
        continue;
      }

      result[index] = i;
      isUsed[i] = true;

      if (i == 1) {
        if (search(n, index + 1, isUsed, result)) {
          return true;
        }
      } else {
        if (index + i < result.size() && result[index + i] == 0) {
          result[index + i] = i;

          if (search(n, index + 1, isUsed, result)) {
            return true;
          }

          result[index + i] = 0;
        }
      }
      isUsed[i] = false;
      result[index] = 0;
    }
    return false;
  }

public:
  vector<int> constructDistancedSequence(int n) {
    vector<int> result(n * 2 - 1, 0);
    vector<bool> isUsed(n + 1, false);

    search(n, 0, isUsed, result);

    return result;
  }
};

int main() {
  int n;
  cin >> n;

  auto result = Solution().constructDistancedSequence(n);

  for (int i = 0; i < result.size(); i++) {
    cout << result[i] << " ";
  }

  cout << endl;
}
