class Solution {
public:
  int numPairsDivisibleBy60(vector<int> &time) {
    vector<int> mods(60);
    int ans = 0;
    for (auto v : time) {
      ans += mods[(6000 - v) % 60];
      mods[v % 60]++;
    }

    return ans;
  }
};
