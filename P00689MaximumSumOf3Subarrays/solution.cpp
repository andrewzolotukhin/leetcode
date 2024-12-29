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

    vector<int> prefix(n + 1, 0);

    for (int i = 1; i <= n; i++) {
      prefix[i] = prefix[i - 1] + nums[i - 1];
    }

    vector<vector<pair<int, int>>> sums(4,
                                        vector<pair<int, int>>(n + 1, {0, 0}));

    for (int arraysCount = 1; arraysCount <= 3; arraysCount++) {
      for (int end = k * arraysCount; end <= n; end++) {
        auto currentSum = prefix[end] - prefix[end - k] +
                          sums[arraysCount - 1][end - k].first;

        if (currentSum > sums[arraysCount][end - 1].first) {
          sums[arraysCount][end] = {currentSum, end - k};
        } else {
          sums[arraysCount][end] = sums[arraysCount][end - 1];
        }
      }
    }

    vector<int> result(3, 0);
    int ce = n;

    for (int i = 3; i >= 1; i--) {
      result[i - 1] = sums[i][ce].second;
      ce = result[i - 1];
    }

    return result;
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
