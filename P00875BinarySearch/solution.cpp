class Solution {
public:
  bool canEat(vector<int> &piles, int k, int h) {
    for (int i = 0; i < piles.size() && h >= 0; i++) {
      h -= (piles[i] + k - 1) / k;
    }
    return h >= 0;
  }
  int minEatingSpeed(vector<int> &piles, int h) {
    sort(piles.begin(), piles.end());
    int l = 1, r = INT_MAX - 1;

    while (l < r) {
      int mid = (l + r) / 2;
      if (canEat(piles, mid, h)) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }
    return l;
  }
};
