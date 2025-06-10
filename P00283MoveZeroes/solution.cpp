class Solution {
private:
  void moveZeroesCorrectSolution(vector<int> &nums) {
    for (int lastNonZeroFoundAt = 0, cur = 0; cur < nums.size(); cur++) {
      if (nums[cur] != 0) {
        swap(nums[lastNonZeroFoundAt++], nums[cur]);
      }
    }
  }

public:
  void moveZeroes(vector<int> &nums) {
    int lnz = nums.size() - 1;
    while (lnz >= 0 && nums[lnz] == 0)
      lnz--;

    while (lnz > -1) {
      int c = 1;
      while (lnz - c >= 0 && nums[lnz - c] != 0)
        c++;

      if (lnz - c < 0)
        break;

      for (int i = 0; i < c; i++) {
        nums[lnz - c + i] = nums[lnz - c + i + 1];
      }
      nums[lnz] = 0;
      while (lnz >= 0 && nums[lnz] == 0)
        lnz--;
    }
  }
};
