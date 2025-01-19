#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int trap(vector<int> &height) {
    if (height.size() < 1)
      return 0;
    int result = 0;

    int n = height.size();
    vector<int> maxL = vector<int>(n), maxR = vector<int>(n);

    maxL[0] = height[0];
    maxR[n - 1] = height[n - 1];

    for (int i = 1; i < n; i++) {
      maxL[i] = max(height[i], maxL[i - 1]);
    }

    for (int i = n - 2; i >= 0; i--) {
      maxR[i] = max(height[i], maxR[i + 1]);
    }

    for (int i = 0; i < n; i++) {
      result += min(maxL[i], maxR[i]) - height[i];
    }

    return result;
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  int n;
  vector<int> nums;

  cin >> n;
  while (n--) {
    int x;
    cin >> x;
    nums.push_back(x);
  }

  Solution sol;

  cout << sol.trap(nums) << endl;
}
