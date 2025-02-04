#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxAscendingSum(vector<int> &nums) {
    int result = nums[0];
    int current = result;
    int n = nums.size();

    for (int i = 1; i < n; i++) {
      if (nums[i] > nums[i - 1]) {
        current += nums[i];
      } else {
        current = nums[i];
      }

      result = max(current, result);
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

  cout << Solution().maxAscendingSum(nums) << endl;
}
