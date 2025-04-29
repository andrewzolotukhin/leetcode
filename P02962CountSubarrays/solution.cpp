class Solution {
public:
  long long countSubarrays(vector<int> &nums, int k) {
    vector<int> maxIndexes;
    int m = INT_MIN;
    for (auto v : nums)
      if (v > m)
        m = v;
    long long ans = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] == m)
        maxIndexes.push_back(i);

      if (maxIndexes.size() >= k) {
        ans += maxIndexes[maxIndexes.size() - k] + 1;
      }
    }
    return ans;
  }
};

/**
2 3 = 13
xxyzzz
xxy
xxyz
xxyzz
xxyzzz
 xy
 xyz
 xyzz
 xyzzz
  y
  yz
  yzz
  yzzz

2 2 = 9
xxyzz
xxyz
xxy
 xyzz
 xyz
 xy
  yzz
  yz
  y
**/
