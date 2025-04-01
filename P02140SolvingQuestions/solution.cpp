#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  long long mostPoints(vector<vector<int>> &questions) {
    int n = questions.size();
    vector<long long> dp(n + 1, 0);
    for (int i = 0; i < n; i++) {
      int idx = min(n, i + 1 + questions[i][1]);
      dp[idx] = max(dp[idx], dp[i] + questions[i][0]);
      dp[i + 1] = max(dp[i + 1], dp[i]);
    }
    return dp[n];
  }
};

int main() {
  int n;
  cin >> n;

  vector<vector<int>> nums(n, vector<int>(2));

  for (int i = 0; i < n; i++) {
    cin >> nums[i][0] >> nums[i][1];
  }

  cout << Solution().mostPoints(nums) << '\n';
}
