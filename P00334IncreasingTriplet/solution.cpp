class Solution {
public:
  bool increasingTriplet(vector<int> &nums) {
    int v1 = INT_MAX, v2 = INT_MAX;
    for (int n : nums) {
      if (n <= v1) {
        v1 = n;
      } else if (n <= v2) {
        v2 = n;
      } else {
        return true;
      }
    }
    return false;
  }
};
