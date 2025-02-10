#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> assignElements(vector<int> &groups, vector<int> &elements) {
    int n = groups.size();
    int m = elements.size();

    int maxGroup = INT_MIN;
    for (int i = 0; i < n; i++) {
      maxGroup = max(maxGroup, groups[i]);
    }

    vector<vector<int>> allDivisors(maxGroup + 1, vector<int>());
    vector<int> elementToIndex(maxGroup + 1, -1);
    vector<int> result(n, -1);

    for (int i = 1; i <= maxGroup; i++) {
      for (int j = i; j <= maxGroup; j += i) {
        allDivisors[j].push_back(i);
      }
    }

    for (int i = 0; i < m; i++) {
      if ((elements[i] > maxGroup) || (elementToIndex[elements[i]] != -1)) {
        continue;
      }
      elementToIndex[elements[i]] = i;
    }

    for (int i = 0; i < n; i++) {
      int minI = INT_MAX;
      for (int j = 0; j < allDivisors[groups[i]].size(); j++) {
        int divisor = allDivisors[groups[i]][j];
        if (elementToIndex[divisor] != -1) {
          minI = min(minI, elementToIndex[divisor]);
        }
      }
      if (minI != INT_MAX) {
        result[i] = minI;
      }
    }

    return result;
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  int n, m;
  cin >> n >> m;
  vector<int> groups(n), elements(m);
  for (int i = 0; i < n; i++) {
    cin >> groups[i];
  }

  for (int i = 0; i < m; i++) {
    cin >> elements[i];
  }

  auto result = Solution().assignElements(groups, elements);

  for (int i = 0; i < result.size(); i++) {
    cout << result[i] << '\n';
  }
}
