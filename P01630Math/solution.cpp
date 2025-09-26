class Solution {
public:
  vector<bool> checkArithmeticSubarrays(vector<int> &nums, vector<int> &l,
                                        vector<int> &r) {
    vector<bool> ans;

    for (int i = 0; i < l.size(); i++) {
      int mn = INT_MAX, sc = INT_MAX, mx = INT_MIN;
      for (int j = l[i]; j <= r[i]; j++) {
        if (nums[j] < mn) {
          mn = nums[j];
        }
        if (nums[j] > mx)
          mx = nums[j];
      }

      if (mn == mx) {
        ans.push_back(true);
        continue;
      }

      int len = r[i] - l[i] + 1;

      if ((mx - mn) % (len - 1) != 0) {
        ans.push_back(false);
        continue;
      }

      int diff = (mx - mn) / (len - 1);
      int total = 0;
      unordered_set<int> seen;
      bool ok = true;
      for (int j = l[i]; j <= r[i]; j++) {
        if ((nums[j] - mn) % diff != 0) {
          ok = false;
          break;
        }
        int k = (nums[j] - mn) / diff;
        seen.insert(k);
        total = max(total, k);
        if (total >= len) {
          ok = false;
          break;
        }
      }

      if (seen.size() != len)
        ok = false;

      ans.push_back(ok);
    }

    return ans;
  }
};
