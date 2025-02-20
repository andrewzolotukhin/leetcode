class Solution {
private:
  void generate(int n, vector<int> &nums, vector<int> current,
                vector<vector<int>> &result) {
    if (n == nums.size() - 1) {
      result.push_back(vector<int>(current.begin(), current.end()));

      auto c = vector<int>(current.begin(), current.end());
      c.push_back(nums[n]);
      result.push_back(c);
      return;
    }

    generate(n + 1, nums, current, result);

    current.push_back(nums[n]);

    generate(n + 1, nums, current, result);
  }

public:
  vector<vector<int>> subsets(vector<int> &nums) {
    vector<vector<int>> result;
    vector<int> current;
    generate(0, nums, current, result);
    return result;
  }
};
