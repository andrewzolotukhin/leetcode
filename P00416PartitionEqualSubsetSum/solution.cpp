class Solution {
public:
  bool canPartition(vector<int> &nums) {
    bitset<10001> bits(1);
    int s = accumulate(nums.begin(), nums.end(), 0);
    if (s & 1)
      return false;
    for (int i = 0; i < nums.size(); i++)
      bits |= bits << nums[i];
    return bits[s / 2];
  }
};
