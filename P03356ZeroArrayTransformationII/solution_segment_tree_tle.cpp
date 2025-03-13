#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  vector<int> maxTree;

  int getMax(int node, int nodeStart, int nodeEnd, int queryStart,
             int queryEnd) {
    if (nodeStart > queryEnd || nodeEnd < queryStart) {
      return 0;
    }

    if (nodeStart >= queryStart && nodeEnd <= queryEnd) {
      return maxTree[node];
    }

    int mid = (nodeStart + nodeEnd) / 2;
    return max(getMax(2 * node, nodeStart, mid, queryStart, queryEnd),
               getMax(2 * node + 1, mid + 1, nodeEnd, queryStart, queryEnd));
  }

  void updateMaxTree(int node, int maxDecrement) {
    maxTree[node] = max(0, maxTree[node] - maxDecrement);
    node /= 2;
    while (node >= 1 && maxTree[node] > 0) {
      maxTree[node] = max(maxTree[2 * node], maxTree[2 * node + 1]);
      node /= 2;
    }
  }

public:
  int minZeroArray(vector<int> &nums, vector<vector<int>> &queries) {
    int n = nums.size(), m = queries.size();

    while (__builtin_popcount(n) != 1) {
      nums.push_back(0);
      n++;
    }

    maxTree.resize(2 * n);

    bool sawOnlyZeros = true;

    for (int i = 0; i < n; i++) {
      maxTree[n + i] = nums[i];
      if (nums[i] != 0) {
        sawOnlyZeros = false;
      }
    }

    if (sawOnlyZeros) {
      return 0;
    }

    for (int i = n - 1; i > 0; i--) {
      maxTree[i] = max(maxTree[2 * i], maxTree[2 * i + 1]);
    }

    for (int i = 0; i < m; i++) {
      int l = queries[i][0], r = queries[i][1], x = queries[i][2];
      if (x <= 0) {
        continue;
      }

      for (int j = l; j <= r; j++) {
        updateMaxTree(n + j, x);
      }

      // int maxVal = getMax(1, 0, n - 1, 0, n - 1);
      int maxVal = maxTree[1];
      if (maxVal == 0) {
        return i + 1;
      }
    }
    return -1;
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  int n, m;
  cin >> n;
  vector<int> nums(n);

  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  cin >> m;

  vector<vector<int>> queries(m, vector<int>(3));

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> queries[i][j];
    }
  }

  cout << Solution().minZeroArray(nums, queries) << endl;
}
