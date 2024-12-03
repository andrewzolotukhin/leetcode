#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int firstMissingPositive(vector<int> &nums) {
    int n = nums.size();

    int i, j = n - 1;

    if (n == 1) {
      return ((nums[0] == 1) ? 2 : 1);
    }

    i = 0;

    while (i < j) {
      if ((nums[j] == j + 1) || (nums[j] < 1) || (nums[j] > n)) {
        j--;
        continue;
      }

      if (nums[i] != i + 1) {
        if (nums[i] < 1 || nums[i] > n) {
          if (nums[j] == nums[i]) {
            j--;
            continue;
          }
          int t = nums[j];
          nums[j] = nums[i];
          nums[i] = t;
          j--;
          // let's decrement i to be the same in the next iteration
          i--;
        } else {
          if (nums[i] != i + 1) {
            int ni = nums[i] - 1;
            if (nums[ni] == nums[i]) {
            } else {
              int t = nums[ni];
              nums[ni] = nums[i];
              nums[i] = t;
              // let's decrement i to be the same in the next iteration
              i--;
            }
          }
        }
      }
      i++;
    }

    if (nums[i] >= 1 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
      int t = nums[nums[i] - 1];
      nums[nums[i] - 1] = nums[i];
      nums[i] = t;
    }

    for (int k = 0; k < n; k++) {
      if (nums[k] != k + 1) {
        return k + 1;
      }
    }
    return n + 1;
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

  auto solution = Solution();

  cout << solution.firstMissingPositive(nums) << endl;
}
