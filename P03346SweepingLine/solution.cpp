class Solution {
public:
  int maxFrequency(vector<int> &nums, int k, int numOperations) {
    map<int, int> state;
    unordered_map<int, int> hash;
    set<int> interval;

    for (int num : nums) {
      hash[num]++;
      interval.insert(num - k);
      interval.insert(num);
      interval.insert(num + k + 1);
      state[num - k]++;
      state[num + k + 1]--;
    }

    int ans = 1, ops = 0;
    for (auto &it : interval) {
      ops += state[it];
      ans = max(ans, hash[it] + min(numOperations, ops - hash[it]));
    }
    return ans;
  }
};
