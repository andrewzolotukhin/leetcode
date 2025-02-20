#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string findDifferentBinaryString(vector<string> &nums) {
    int n = nums.size();
    unordered_map<int, bool> seen;

    for (auto num : nums) {
      int v = 0;
      int base = 1;
      for (int i = 0; i < n; i++) {
        if (num[n - 1 - i] == '1') {
          v += base;
        }
        base <<= 1;
      }
      seen[v] = true;
    }

    for (int i = 0; i < (1 << (n + 1)); i++) {
      if (seen.count(i) == 0) {
        string result(n, '0');

        for (int j = 0; j < n; j++) {
          if (i & (1 << j)) {
            result[n - 1 - j] = '1';
          }
        }

        return result;
      }
    }

    assert(false);
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  int n;
  cin >> n;

  vector<string> nums(n);

  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  cout << Solution().findDifferentBinaryString(nums) << endl;
}
