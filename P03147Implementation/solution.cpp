class Solution {
public:
  int maximumEnergy(vector<int> &energy, int k) {
    int ans = INT_MIN;
    for (int i = energy.size() - 1; i >= max(0, (int)energy.size() - k); i--) {
      int r = energy[i];
      ans = max(ans, r);
      int j = i - k;

      while (j >= 0) {
        r += energy[j];
        ans = max(ans, r);
        j -= k;
      }
    }

    return ans;
  }
};
