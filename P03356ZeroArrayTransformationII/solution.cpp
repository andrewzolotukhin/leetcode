#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minZeroArray(vector<int> &nums, vector<vector<int>> &queries) {
    int n = nums.size();
    int total = 0;
    int q = 0;
    vector<int> da(n + 1, 0);

    for (int i = 0; i < n; i++) {
      while (total + da[i] < nums[i]) {
        if (q > queries.size() - 1) {
          return -1;
        }

        int l = queries[q][0];
        int r = queries[q][1];
        int v = queries[q][2];

        if (r >= i) {
          da[max(l, i)] += v;
          da[r + 1] -= v;
        }
        q++;
      }
      total += da[i];
    }

    return q;
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
