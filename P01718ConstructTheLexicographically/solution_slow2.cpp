#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  bool search(int n, int firstEmpty, int remaining, vector<bool> &isUsed,
              vector<int> &current, vector<int> &best) {
    int lastIndex = (n - 1) * 2;
    if (remaining == 0) {
      if (current > best) {
        best = current;
        return true;
      }
      return false;
    }

    for (int i = n; i >= 1; i--) {
      if (isUsed[i])
        continue;
      if (i > 1 && firstEmpty + i > lastIndex)
        return false;
      if (current[firstEmpty + i] != 0)
        continue;
      int newFirstEmpty = -1;
      current[firstEmpty] = i;

      for (int j = 0; j <= lastIndex; j++) {
        if (current[j] == 0) {
          newFirstEmpty = j;
          break;
        }
      }

      if (newFirstEmpty == -1 && remaining > 1) {
        return false;
      }

      isUsed[i] = true;
      if (i != 1) {
        current[firstEmpty + i] = i;
      }

      if (search(n, newFirstEmpty, remaining - 1, isUsed, current, best)) {
        return true;
      }

      isUsed[i] = false;
      current[firstEmpty] = 0;
      if (i != 1) {
        current[firstEmpty + i] = 0;
      }
    }

    return false;
  }

public:
  vector<int> constructDistancedSequence(int n) {
    vector<int> result(50, 0);
    vector<bool> isUsed(n + 1, false);

    vector<int> current(50, 0);
    search(n, 0, n, isUsed, current, result);

    return vector<int>(result.begin(), result.begin() + 2 * (n - 1) + 1);
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
