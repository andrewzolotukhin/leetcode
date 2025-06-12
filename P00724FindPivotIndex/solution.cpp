class Solution {
public:
  int pivotIndex(vector<int> &nums) {
    int n = nums.size();
    vector<int> prefix(n + 1, 0);
    for (int i = 1; i <= n; i++) {
      prefix[i] = prefix[i - 1] + nums[i - 1];
    }

    for (int i = 0; i < n; i++) {
      if (prefix[i] == prefix[n] - prefix[i + 1])
        return i;
    }

    return -1;
  }
};
