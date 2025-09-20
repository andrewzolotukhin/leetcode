class Solution {
public:
  long long minOperations(vector<int> &nums1, vector<int> &nums2, int k) {
    int n = nums1.size();
    if (k == 0) {
      for (int i = 0; i < n; i++) {
        if (nums1[i] != nums2[i])
          return -1;
      }
      return 0;
    }
    long long inc = 0, dec = 0;

    for (int i = 0; i < n; i++) {
      if (nums1[i] == nums2[i])
        continue;

      int diff = abs(nums1[i] - nums2[i]);
      if (diff % k != 0)
        return -1;
      if (nums1[i] > nums2[i]) {
        dec += diff / k;
      } else {
        inc += diff / k;
      }
    }

    if (inc == dec)
      return inc;
    return -1;
  }
};
