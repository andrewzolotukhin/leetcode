class Solution {
public:
  vector<string> summaryRanges(vector<int> &nums) {
    int start = 0;
    int end = 0;

    vector<string> ans;
    while (end < nums.size()) {
      while (end < nums.size() - 1 && nums[end + 1] == nums[end] + 1) {
        end++;
      }
      if (start != end) {
        ans.push_back(to_string(nums[start]) + "->" + to_string(nums[end]));
      } else {
        ans.push_back(to_string(nums[start]));
      }

      start = end + 1;
      end = start;
    }

    return ans;
  }
};
