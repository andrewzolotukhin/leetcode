#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int xorAllNums(vector<int> &nums1, vector<int> &nums2) {
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());

    vector<int> nnums1, nnums2;

    int prev = nums1[0];
    int cnt = 1;
    for (int i = 1; i < nums1.size(); i++) {
      if (prev == nums1[i]) {
        cnt++;
      } else {
        if (cnt & 1) {
          nnums1.push_back(prev);
        }
        cnt = 1;
        prev = nums1[i];
      }
    }

    if (cnt & 1) {
      nnums1.push_back(prev);
    }

    prev = nums2[0];
    cnt = 1;
    for (int i = 1; i < nums2.size(); i++) {
      if (prev == nums2[i]) {
        cnt++;
      } else {
        if (cnt & 1) {
          nnums2.push_back(prev);
        }
        cnt = 1;
        prev = nums2[i];
      }
    }

    if (cnt & 1) {
      nnums2.push_back(prev);
    }

    if (nnums1.size() == 0 || nnums2.size() == 0)
      return 0;

    int result = nnums1[0] ^ nnums2[0];

    bool c = true;
    for (int i = 0; i < nnums1.size(); i++) {
      for (int j = 0; j < nnums2.size(); j++) {
        if (i == 0 && j == 0)
          continue;
        result ^= nnums1[i] ^ nnums2[j];
      }
    }

    return result;
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  int n, m, x;
  cin >> n >> m;
  vector<int> nums1, nums2;

  while (n--) {
    cin >> x;
    nums1.push_back(x);
  }

  while (m--) {
    cin >> x;
    nums2.push_back(x);
  }

  Solution s;

  cout << s.xorAllNums(nums1, nums2) << '\n';
}
