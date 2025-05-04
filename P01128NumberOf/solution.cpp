class Solution {
public:
  int numEquivDominoPairs(vector<vector<int>> &dominoes) {
    unordered_map<int, int> freq;
    int ans = 0;

    for (int i = 0; i < dominoes.size(); i++) {
      if (dominoes[i][0] > dominoes[i][1]) {
        swap(dominoes[i][0], dominoes[i][1]);
      }
      int k = (dominoes[i][0] << 8) | dominoes[i][1];
      ans += freq[k]++;
    }

    return ans;
  }
};
