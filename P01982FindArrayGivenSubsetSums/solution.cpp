class Solution {
public:
  vector<int> recoverArray(int n, vector<int> &sums) {
    sort(sums.begin(), sums.end());

    vector<int> result;

    while (sums.size() > 1) {
      if (sums.size() == 2) {
        result.push_back(sums[0] + sums[1]);
        break;
      }
      vector<int> f, s;
      bool firstHasZero = false;
      int diff = sums[1] - sums[0];
      int j = 0;
      for (int i = 0; i < sums.size(); i++) {
        if (sums[i] == INT_MIN)
          continue;
        firstHasZero |= sums[i] == 0;
        f.push_back(sums[i]);
        s.push_back(sums[i] + diff);
        for (j = max(j + 1, i + 1); sums[j] != diff + sums[i]; j++)
          ;
        sums[j] = INT_MIN;
      }
      result.push_back(diff * (firstHasZero ? 1 : -1));
      sums = firstHasZero ? f : s;
    }

    return result;
  }
};
