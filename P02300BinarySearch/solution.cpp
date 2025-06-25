class Solution {
public:
  vector<int> successfulPairs(vector<int> &spells, vector<int> &potions,
                              long long success) {
    sort(potions.begin(), potions.end());
    int n = spells.size(), m = potions.size();
    vector<int> ans(n);

    for (int i = 0; i < n; i++) {
      int l = 0, r = m - 1;
      if (1LL * spells[i] * potions[m - 1] < success) {
        ans[i] = 0;
        continue;
      }
      if (1LL * spells[i] * potions[0] >= success) {
        ans[i] = m;
        continue;
      }
      while (l < r) {
        int mid = (l + r) / 2;
        if (1LL * spells[i] * potions[mid] >= success) {
          r = mid;
        } else {
          l = mid + 1;
        }
      }

      ans[i] = m - l;
    }
    return ans;
  }
};
