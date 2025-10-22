class Solution {
public:
  int maxFrequency(vector<int> &nums, int k, int numOperations) {
    map<int, int> state;
    unordered_map<int, int> hash;
    set<long long> interval;

    for (long long num : nums) {
      hash[num]++;
      interval.insert((long long)num - k);
      interval.insert((long long)num);
      interval.insert((long long)num + k + 1);
      state[(long long)num - k]++;
      state[(long long)num + k + 1]--;
    }

    long long ans = 1, ops = 0;
    for (auto &it : interval) {
      ops += state[it];
      ans = max(ans, (long long)hash[it] + min((long long)numOperations,
                                               (long long)ops - hash[it]));
    }
    return ans;
  }
};
