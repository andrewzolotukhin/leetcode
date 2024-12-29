#include <bits/stdc++.h>
#include <climits>
using namespace std;

class Solution {
public:
  vector<int> maxSumOfThreeSubarrays(vector<int> &nums, int k) {
    int n = nums.size();

    if (3 * k > nums.size()) {
      return {};
    }

    int window = 0;
    int s = n - k + 1;
    vector<int> sums = vector<int>(s, 0);

    for (int i = 0; i < k; i++) {
      window += nums[i];
    }

    sums[0] = window;

    for (int i = 1; i < s; i++) {
      window += nums[i + k - 1] - nums[i - 1];
      sums[i] = window;
    }

    vector<vector<int>> memo = vector<vector<int>>(s, vector<int>(4, -1));

    dp(sums, k, 0, 3, memo);

    vector<int> result;

    find(sums, k, 0, 3, memo, result);

    return result;
  }

  int dp(vector<int> &sums, int k, int index, int remaining,
         vector<vector<int>> &memo) {
    if (remaining == 0) {
      return 0;
    }

    if (index >= sums.size()) {
      return remaining > 0 ? INT_MIN : 0;
    }

    if (memo[index][remaining] != -1) {
      return memo[index][remaining];
    }

    auto withCurrent =
        sums[index] + dp(sums, k, index + k, remaining - 1, memo);
    auto next = dp(sums, k, index + 1, remaining, memo);

    memo[index][remaining] = max(withCurrent, next);

    return memo[index][remaining];
  }

  void find(vector<int> &sums, int k, int index, int remaining,
            vector<vector<int>> &memo, vector<int> &result) {
    if (index >= sums.size())
      return;
    if (remaining == 0)
      return;

    auto with = sums[index] + dp(sums, k, index + k, remaining - 1, memo);
    auto without = dp(sums, k, index + 1, remaining, memo);

    if (with >= without) {
      result.push_back(index);
      find(sums, k, index + k, remaining - 1, memo, result);
    } else {
      find(sums, k, index + 1, remaining, memo, result);
    }
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  int n, k;
  cin >> n >> k;
  vector<int> nums;

  while (n--) {
    int l;
    cin >> l;
    nums.push_back(l);
  }

  Solution s;
  auto res = s.maxSumOfThreeSubarrays(nums, k);

  for (auto rr : res) {
    cout << rr << " ";
  }
  cout << '\n';
}
