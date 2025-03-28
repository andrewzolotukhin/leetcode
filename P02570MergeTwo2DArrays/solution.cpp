class Solution {
public:
  vector<vector<int>> mergeArrays(vector<vector<int>> &nums1,
                                  vector<vector<int>> &nums2) {
    vector<vector<int>> result;

    int n = nums1.size(), m = nums2.size(), i = 0, j = 0;

    while ((i < n) || (j < m)) {
      if (i < n && j < m) {

        if (nums1[i][0] < nums2[j][0]) {
          result.push_back(nums1[i++]);
          continue;
        }

        if (nums1[i][0] > nums2[j][0]) {
          result.push_back(nums2[j++]);
          continue;
        }

        result.push_back({nums1[i][0], nums1[i][1] + nums2[j][1]});
        i++;
        j++;

        continue;
      }

      if (i < n) {
        result.push_back(nums1[i++]);
        continue;
      }

      if (j < m) {
        result.push_back(nums2[j++]);
        continue;
      }

      assert(false);
    }

    return result;
  }
};
