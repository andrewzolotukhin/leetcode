#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  long long countBadPairs(vector<int> &nums) {
    long long result = 0;
    int n = nums.size();
    unordered_map<int, int> d;
    for (int i = 0; i < n; i++) {
      int difference = i - nums[i];
      result += i - d[difference];
      d[difference]++;
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

  cout << Solution().countBadPairs(nums) << endl;
}
