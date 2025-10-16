class Solution {
public:
  int findSmallestInteger(vector<int> &nums, int value) {
    vector<int> rems(value, 0);
    for (int i = 0; i < nums.size(); i++) {
      int k = (value + (nums[i] % value)) % value;
      rems[k]++;
    }

    int m = 0;
    while (rems[m % value] > 0) {
      rems[m % value]--;
      m++;
    }
    return m;
  }
};
