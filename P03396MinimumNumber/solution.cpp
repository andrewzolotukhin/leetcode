class Solution {
public:
  int minimumOperations(vector<int> &nums) {
    vector<int> freq(101, 0);
    int uniq = 0;
    for (auto v : nums) {
      freq[v]++;
      if (freq[v] == 1) {
        uniq++;
      }
    }

    int ans = 0;
    int n = nums.size();
    for (int i = 0; i < n; i += 3) {
      int rem = n - i;
      if (uniq == rem)
        break;
      // cout << i << ' ' << rem << '\n';
      if (i >= n - 3) {
        ans++;
        break;
      }

      freq[nums[i]]--;
      uniq -= (freq[nums[i]] == 0 ? 1 : 0);
      freq[nums[i + 1]]--;
      uniq -= (freq[nums[i + 1]] == 0 ? 1 : 0);
      freq[nums[i + 2]]--;
      uniq -= (freq[nums[i + 2]] == 0 ? 1 : 0);
      // cout << uniq << '\n';
      ans++;
      if (uniq == rem)
        break;
    }

    return ans;
  }
};
