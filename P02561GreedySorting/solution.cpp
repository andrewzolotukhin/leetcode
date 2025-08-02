class Solution {
public:
  long long minCost(vector<int> &basket1, vector<int> &basket2) {
    unordered_map<int, int> freq1, freq2, freq3;
    for (const auto &f : basket1) {
      freq1[f]++;
      freq3[f]++;
    }
    for (const auto &f : basket2) {
      freq2[f]++;
      freq3[f]++;
    }

    int mn = INT_MAX;

    long long ans = 0;
    vector<int> swaps;
    for (auto [k, v] : freq3) {
      mn = min(mn, k);
      if (v & 1)
        return -1;
      int diff = abs(freq1[k] - freq2[k]) / 2;
      for (int i = 0; i < diff; i++) {
        swaps.push_back(k);
      }
    }

    sort(swaps.begin(), swaps.end());
    for (int i = 0; i < swaps.size() / 2; i++) {
      ans += min(swaps[i], 2 * mn);
    }
    return ans;
  }
};
