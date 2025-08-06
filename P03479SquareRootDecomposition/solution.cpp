class Solution {
public:
  int numOfUnplacedFruits(vector<int> &fruits, vector<int> &baskets) {
    int sq = sqrt(fruits.size());
    int s = (fruits.size() + sq - 1) / sq;
    vector<int> maxV(s, 0);
    int b = 0;
    int i = 0;
    for (int i = 0; i < baskets.size(); i++) {
      maxV[i / sq] = max(maxV[i / sq], baskets[i]);
    }

    int ans = fruits.size();

    for (auto f : fruits) {
      int idx = -1;
      for (int j = 0; j < s; j++) {
        if (maxV[j] < f)
          continue;
        maxV[j] = 0;
        for (int k = sq * j; k < sq * (j + 1) && k < baskets.size(); k++) {
          if (idx == -1 && baskets[k] >= f) {
            idx = k;
            baskets[k] = 0;
          }
          maxV[j] = max(maxV[j], baskets[k]);
        }
        if (idx != -1)
          break;
      }

      if (idx != -1) {
        ans--;
      }
    }

    return ans;
  }
};
