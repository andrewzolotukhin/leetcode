class Solution {
public:
  long long countInterestingSubarrays(vector<int> &nums, int modulo, int k) {
    int n = nums.size();
    vector<long long> prefix(n + 1, 0);
    for (int i = 0; i < n; i++) {
      prefix[i + 1] = prefix[i] + ((nums[i] % modulo == k) ? 1 : 0);
    }

    // prefix[j] - prefix[i] = k | mod m
    // prefix[i] = prefix[j] + m -k | mod m

    long long ans = 0;
    unordered_map<int, int> freq;
    freq[0] = 1;

    for (int i = 0; i < n; i++) {
      ans += freq[(prefix[i + 1] + modulo - k) % modulo];
      freq[prefix[i + 1] % modulo]++;
    }

    return ans;
  }
};
