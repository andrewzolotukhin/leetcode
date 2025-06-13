class Solution {
private:
  int canFit(vector<int> &nums, int t) {
    int c = 0, i = 0;
    while (i < nums.size() - 1) {
      if (nums[i + 1] - nums[i] <= t) {
        c++;
        i++;
      }
      i++;
    }
    return c;
  }

public:
  int minimizeMax(vector<int> &nums, int p) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int l = 0, r = nums[n - 1] - nums[0];

    while (l < r) {
      int m = (l + r) / 2;

      if (canFit(nums, m) >= p) {
        r = m;
      } else {
        l = m + 1;
      }
    }
    return l;
  }
};
