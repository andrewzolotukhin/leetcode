#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int longestMonotonicSubarray(vector<int> &nums) {
    int result = 1;

    int n = nums.size();
    int inc = 0;
    int dec = 0;

    for (int i = 1; i < n; i++) {
      if (nums[i] > nums[i - 1]) {
        inc++;
        dec = 0;
      }
      if (nums[i] < nums[i - 1]) {
        inc = 0;
        dec++;
      }
      if (nums[i] == nums[i - 1]) {
        inc = 0;
        dec = 0;
      }

      result = max(result, max(inc, dec) + 1);
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

  cout << Solution().longestMonotonicSubarray(nums) << endl;
}
