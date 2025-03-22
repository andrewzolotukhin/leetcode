class Solution {
public:
  void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
    int f = m - 1, s = n - 1, i = n + m - 1;

    while (i >= 0) {
      if (f >= 0 && s >= 0) {
        if (nums1[f] >= nums2[s]) {
          nums1[i] = nums1[f];
          f--;
        } else {
          nums1[i] = nums2[s];
          s--;
        }
      } else {
        if (f >= 0) {
          nums1[i] = nums1[f];
          f--;
        } else {
          nums1[i] = nums2[s];
          s--;
        }
      }
      i--;
    }
  }
};
