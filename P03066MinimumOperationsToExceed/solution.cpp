#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minOperations(vector<int> &nums, int k) {
    int result = 0;
    priority_queue<long, vector<long>, greater<long>> pq(nums.begin(),
                                                         nums.end());
    while (pq.size() > 1 && pq.top() < k) {
      long a = pq.top();
      pq.pop();

      long b = pq.top();
      pq.pop();

      result++;
      pq.push(min(a, b) * 2 + max(a, b));
    }
    return result;
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  int n, k;
  cin >> n >> k;
  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  cout << Solution().minOperations(nums, k) << '\n';
}
