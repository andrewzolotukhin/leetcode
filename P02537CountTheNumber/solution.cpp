class Solution {
public:
  long long countGood(vector<int> &nums, int k) {
    int n = nums.size();

    unordered_map<int, int> freq;

    long long ans = 0;
    int r = -1, pairs = 0;

    for (int i = 0; i < n; i++) {
      while (pairs < k && r < n - 1) {
        r++;
        pairs += freq[nums[r]];
        freq[nums[r]]++;
      }
      if (pairs >= k) {
        ans += n - r;
      }
      freq[nums[i]]--;
      pairs -= freq[nums[i]];
    }
    return ans;
  }
};
