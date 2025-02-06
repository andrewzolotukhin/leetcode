#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  long long perm(long long n, long long m) {
    long long result = 1;
    for (int i = n - m + 1; i <= n; i++) {
      result *= (long long)i;
    }
    return result;
  }

public:
  int tupleSameProduct(vector<int> &nums) {
    priority_queue<int> q;

    int n = nums.size();
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        q.push(nums[i] * nums[j]);
      }
    }

    int currVal = q.top();
    int currCount = 0;
    int result = 0;

    while (!q.empty()) {
      if (q.top() == currVal) {
        currCount++;
        q.pop();
      } else {
        if (currCount > 1) {
          result += 4 * (int)perm(currCount, 2);
        }
        currCount = 0;
        currVal = q.top();
      }
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

  cout << Solution().tupleSameProduct(nums) << endl;
}
