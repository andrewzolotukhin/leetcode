#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void solve(vector<int> &dp, vector<int> &nums, int index) {
    if (index >= dp.size())
      return;
    if (dp[index] != -1)
      return;

    dp[index] = 1;
    for (int i = 1; i <= nums[index]; i++) {
      if (index + i >= nums.size())
        break;
      solve(dp, nums, index + i);
    }
  }

  bool canJump(vector<int> &nums) {
    vector<int> dp(nums.size(), -1);
    solve(dp, nums, 0);
    return dp[nums.size() - 1] > 0;
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  int n;
  vector<int> nums;
  cin >> n;
  while (n--) {
    int a;
    cin >> a;
    nums.push_back(a);
  }

  Solution s;
  cout << (s.canJump(nums) ? 1 : 0) << '\n';
}
