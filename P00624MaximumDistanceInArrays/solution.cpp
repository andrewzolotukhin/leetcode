#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxDistance(vector<vector<int>> &arrays) {
    int minVal = INT_MAX, maxVal = INT_MIN;
    int minValIndex, maxValIndex;
    for (int i = 0; i < arrays.size(); i++) {
      if (arrays[i][0] < minVal) {
        minVal = arrays[i][0];
        minValIndex = i;
      }
      if (arrays[i][arrays[i].size() - 1] > maxVal) {
        maxVal = arrays[i][arrays[i].size() - 1];
        maxValIndex = i;
      }
    }

    if (minValIndex == maxValIndex) {
      int nMinVal = INT_MAX;
      for (int i = 0; i < arrays.size(); i++) {
        if (i == minValIndex)
          continue;
        nMinVal = min(nMinVal, arrays[i][0]);
      }

      int candidate = maxVal - nMinVal;

      int nMaxVal = INT_MIN;
      for (int i = 0; i < arrays.size(); i++) {
        if (i == maxValIndex)
          continue;
        nMaxVal = max(nMaxVal, arrays[i][arrays[i].size() - 1]);
      }

      candidate = max(candidate, nMaxVal - minVal);

      return candidate;
    }

    return maxVal - minVal;
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  int n;
  cin >> n;
  vector<vector<int>> arrays;

  for (int i = 0; i < n; i++) {
    int m;
    cin >> m;
    vector<int> array(m);
    for (int j = 0; j < m; j++) {
      cin >> array[j];
    }
    arrays.push_back(array);
  }

  cout << Solution().maxDistance(arrays) << endl;
}
