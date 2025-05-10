class Solution {
public:
  long long minSum(vector<int> &nums1, vector<int> &nums2) {
    int n1 = nums1.size(), n2 = nums2.size();
    long long s1 = 0, s2 = 0;
    int z1 = 0, z2 = 0;
    for (int i = 0; i < n1; i++) {
      s1 += nums1[i];
      if (nums1[i] == 0)
        z1++;
    }
    for (int i = 0; i < n2; i++) {
      s2 += nums2[i];
      if (nums2[i] == 0)
        z2++;
    }

    if (z1 == 0 && z2 == 0 && s1 != s2)
      return -1;
    if (z2 == 0 && s1 + z1 > s2)
      return -1;
    if (z1 == 0 && s2 + z2 > s1)
      return -1;

    return max(s1 + z1, s2 + z2);
  }
};
