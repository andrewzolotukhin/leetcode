#include <bits/stdc++.h>
#include <climits>
using namespace std;

class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    // Kadane's algorithm, O(n) time complexity
    // https://en.wikipedia.org/wiki/Maximum_subarray_problem

    int maxSum = nums[0];
    int currSum = nums[0];
    for (int i = 1; i < nums.size(); i++) {
      currSum = max(nums[i], currSum + nums[i]);
      maxSum = max(maxSum, currSum);
    }

    return maxSum;
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  int n;

  cin >> n;

  vector<int> nums;

  while (n--) {
    int k;
    cin >> k;
    nums.push_back(k);
  }

  Solution s;

  cout << s.maxSubArray(nums) << '\n';
}
