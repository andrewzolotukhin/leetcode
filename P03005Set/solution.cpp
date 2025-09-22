class Solution {
public:
  int maxFrequencyElements(vector<int> &nums) {
    unordered_map<int, int> freq;
    int mf = 0;
    for (auto v : nums) {
      if (++freq[v] > mf) {
        mf = freq[v];
      }
    }
    int ans = 0;
    for (auto [k, v] : freq) {
      if (v == mf)
        ans++;
    }
    return ans * mf;
  }
};
