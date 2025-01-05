#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int mgcd(vector<int> &nums, int start, int end) {
    int result = nums[start];
    for (int i = start + 1; i <= end; i++) {
      result = gcd(result, nums[i]);
    }
    return result;
  }

  int mlcm(vector<int> &nums, int start, long long end) {
    int result = nums[start];
    for (int i = start + 1; i <= end; i++) {
      result = lcm(result, nums[i]);
    }
    return result;
  }

  long long product(vector<int> &nums, int start, int end, long long mod) {
    long long result = nums[start];
    for (int i = start + 1; i <= end; i++) {
      result = (result * nums[i]) % mod;
    }
    return result % mod;
  }

  int maxLength(vector<int> &nums) {
    long long mod = 1000000007;

    int maxLength = 0;

    for (int i = 0; i < nums.size() - 1; i++) {
      for (int j = i + 1; j < nums.size(); j++) {
        if (j - i + 1 <= maxLength)
          continue;
        if ((long long)(mgcd(nums, i, j) * mlcm(nums, i, j)) % mod ==
            product(nums, i, j, mod)) {
          if (j - i + 1 > maxLength) {
            maxLength = j - i + 1;
          }
        }
      }
    }

    return maxLength;
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  Solution s;

  vector<int> nums;
  int n;
  cin >> n;

  while (n--) {
    int k;
    cin >> k;
    nums.push_back(k);
  }

  cout << s.maxLength(nums) << '\n';
}
