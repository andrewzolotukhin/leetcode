#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int trap(vector<int> &height) {
    if (height.size() < 1)
      return 0;
    int result = 0;
    int l = 0, r = height.size() - 1;
    int e = 0, ml = 0, mr = 0;
    while (l <= r) {
      if (height[l] < height[r]) {
        if (height[l] < ml) {
          e += ml - height[l];
        }
        ml = max(ml, height[l]);
        l++;
      } else {
        if (height[r] < mr) {
          e += mr - height[r];
        }
        mr = max(mr, height[r]);
        r--;
      }
    }
    return e;
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
