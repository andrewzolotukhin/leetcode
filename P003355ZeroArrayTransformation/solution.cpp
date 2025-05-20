class Solution {
public:
  bool isZeroArray(vector<int> &nums, vector<vector<int>> &queries) {
    vector<int> change(nums.size() + 1, 0);

    for (auto q : queries) {
      change[q[0]]--;
      change[q[1] + 1]++;
    }

    int sum = 0;
    int d = 0;

    for (int i = 0; i < nums.size(); i++) {
      d += change[i];
      // cout << d << ' ';
      if (nums[i] + d > 0)
        return false;
    }

    return true;
  }
};
