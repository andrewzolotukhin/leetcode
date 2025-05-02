class Solution {
public:
  int longestConsecutive(vector<int> &nums) {
    unordered_map<int, int> mr;
    int ans = 0;
    for (int i : nums)
      if (!mr[i]) {
        mr[i] = mr[i - 1] + mr[i + 1] + 1;
        mr[i - mr[i - 1]] = mr[i];
        mr[i + mr[i + 1]] = mr[i];
        if (ans < mr[i])
          ans = mr[i];
      }
    return ans;
  }
};
