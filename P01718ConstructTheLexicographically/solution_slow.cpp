#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  int comp = 0;
  void search(int n, int firstEmpty, int remaining, vector<bool> &isUsed,
              vector<int> &current, vector<int> &best) {
    int lastIndex = (n - 1) * 2;
    if (remaining == 0) {
      cout << ++comp << '\n';
      if (current > best) {
        best = current;
      }
      return;
    }

    for (int i = n; i >= 1; i--) {
      if (isUsed[i])
        continue;
      if (i > 1 && firstEmpty + i > lastIndex)
        return;
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
        return;
      }

      isUsed[i] = true;
      if (i != 1) {
        current[firstEmpty + i] = i;
      }

      search(n, newFirstEmpty, remaining - 1, isUsed, current, best);
      isUsed[i] = false;
      current[firstEmpty] = 0;
      if (i != 1) {
        current[firstEmpty + i] = 0;
      }
    }

    return;
  }

public:
  vector<int> constructDistancedSequence(int n) {
    vector<int> result(50, 0);
    vector<bool> isUsed(n, false);
    for (int i = n; i <= 1; i--) {
      isUsed.push_back(i);
    }

    vector<int> current(50, 0);
    search(n, 0, n, isUsed, current, result);

    return result;
  }
};

int main() {
  int n;
  cin >> n;

  auto result = Solution().constructDistancedSequence(n);

  for (int i = 0; i <= 2 * (n - 1); i++) {
    cout << result[i] << " ";
  }

  cout << endl;
}
