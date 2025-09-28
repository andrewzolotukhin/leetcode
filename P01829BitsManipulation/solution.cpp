class Solution {
public:
  vector<int> getMaximumXor(vector<int> &nums, int maximumBit) {
    vector<int> ans;
    vector<int> prefix(nums.size() + 1, 0);
    prefix[0] = nums[0];
    for (int i = 1; i < nums.size(); i++) {
      prefix[i] = prefix[i - 1] ^ nums[i];
    }

    for (int i = 0; i < nums.size(); i++) {
      ans.push_back(prefix[nums.size() - i - 1] ^ ((1 << (maximumBit)) - 1));
    }
    return ans;
  }
};
