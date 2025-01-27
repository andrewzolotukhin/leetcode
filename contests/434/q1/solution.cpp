#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int countPartitions(vector<int> &nums) {
    int n = nums.size();
    vector<int> sums(n + 1, 0);

    for (int i = 0; i < n; i++) {
      sums[i + 1] = sums[i] + nums[i];
    }

    int result = 0;
    for (int i = 0; i < n - 1; i++) {
      if (abs(sums[i + 1] - sums[n] + sums[i + 1]) % 2 == 0) {
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

  Solution solution;

  cout << solution.countPartitions(nums) << endl;
}
