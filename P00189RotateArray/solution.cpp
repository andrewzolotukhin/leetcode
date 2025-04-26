class Solution {
private:
  void reverse(vector<int> &nums, int start, int end) {
    for (int i = 0; i < (end - start + 1) / 2; i++) {
      swap(nums[start + i], nums[end - i]);
    }
  }

public:
  void rotate(vector<int> &nums, int k) {
    // 1 2 3 4 5 6 7
    // 5 6 7 1 2 3 4

    // 7 6 5 4 3 2 1
    // 5 6 7 1 2 3 4

    int n = nums.size();
    k %= n;
    if (k == 0)
      return;
    reverse(nums, 0, n - 1);
    reverse(nums, 0, k - 1);
    reverse(nums, k, n - 1);
  }
};
