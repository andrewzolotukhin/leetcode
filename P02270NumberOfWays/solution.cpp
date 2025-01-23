#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int waysToSplitArray(vector<int> &nums) {
    int n = nums.size();
    vector<long long> sum(n + 1, 0LL);
    for (int i = 0; i < n; i++) {
      sum[i + 1] = sum[i] + (long long)nums[i];
    }

    int result = 0;

    for (int i = 0; i < n - 1; i++) {
      if (sum[i + 1] >= (sum[n] - sum[i + 1])) {
        result++;
      }
    }

    return result;
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  int n;
  cin >> n;
  vector<int> nums(n);

  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  Solution sol;

  cout << sol.waysToSplitArray(nums) << endl;
}
