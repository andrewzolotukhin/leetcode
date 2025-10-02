class Solution {
public:
  int maxCoins(vector<int> &piles) {
    sort(piles.rbegin(), piles.rend());

    int ans = 0, j = piles.size();
    for (int i = 1; i <= piles.size() / 3 * 2; i += 2) {
      ans += piles[i];
    }

    return ans;
  }
};
