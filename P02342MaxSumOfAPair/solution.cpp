#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  map<int, int> digitSums;
  int getDigitSum(int n) {
    if (digitSums.count(n)) {
      return digitSums[n];
    }
    int sum = 0;
    while (n > 0) {
      sum += n % 10;
      n /= 10;
    }
    return digitSums[n] = sum;
  }

public:
  int maximumSum(vector<int> &nums) {
    map<int, priority_queue<int>> mp;

    int n = nums.size();
    for (int i = 0; i < n; i++) {
      int digitSum = getDigitSum(nums[i]);
      mp[digitSum].push(nums[i]);
    }

    int result = -1;

    vector<int> candidates;

    for (auto [s, q] : mp) {
      if (q.size() < 2) {
        continue;
      }
      int v1 = q.top();
      q.pop();
      int v2 = q.top();
      candidates.push_back(v1 + v2);
    }

    if (candidates.size() > 0) {
      sort(candidates.begin(), candidates.end());
      result = candidates[candidates.size() - 1];
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

  cout << Solution().maximumSum(nums) << '\n';
}
