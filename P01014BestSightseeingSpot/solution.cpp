class Solution {
public:
  int maxScoreSightseeingPair(vector<int> &values) {
    int ans = 0;
    int maxv = values[0] - 1;
    for (int i = 1; i < values.size(); i++) {
      ans = max(ans, maxv + values[i]);
      maxv = max(maxv, values[i]);
      maxv--;
    }

    return ans;
  }
};
