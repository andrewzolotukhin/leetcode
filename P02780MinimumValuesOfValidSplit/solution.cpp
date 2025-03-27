class Solution {
public:
  int minimumIndex(vector<int> &nums) {
    unordered_map<int, int> orm, olm;

    int n = nums.size();
    for (int i = 0; i < n; i++) {
      orm[nums[i]]++;
    }

    for (int i = 0; i < n - 1; i++) {
      int val = nums[i];

      int ls = i + 1;
      int rs = n - i - 1;

      if (rs < 1)
        continue;
      orm[val]--;
      olm[val]++;
      if (olm[val] * 2 > ls && orm[val] * 2 > rs) {
        return i;
      }
    }

    return -1;
  }
};
