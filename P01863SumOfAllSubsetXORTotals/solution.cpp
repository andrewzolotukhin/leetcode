class Solution {
private:
  void calc(vector<int> &current, vector<int> &nums, int usedSize,
            vector<bool> &used, int &res, int start) {
    if (current.size()) {
      // for(auto c: current) cout << c << ' ';
      // cout << '\n';
      int t = current[0];
      for (int i = 1; i < current.size(); i++) {
        t ^= current[i];
      }
      res += t;
    }

    for (int i = start; i < used.size(); i++) {
      if (used[i])
        continue;
      used[i] = true;
      current.push_back(nums[i]);
      calc(current, nums, usedSize + 1, used, res, i);
      current.pop_back();
      used[i] = false;
    }
  }

public:
  int subsetXORSum(vector<int> &nums) {
    int ans = 0;
    int n = nums.size();
    vector<bool> used(n, false);
    vector<int> curr;

    calc(curr, nums, 0, used, ans, 0);
    return ans;
  }
};
