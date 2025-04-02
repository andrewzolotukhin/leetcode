class Solution {
public:
  int buttonWithLongestTime(vector<vector<int>> &events) {
    int ans = INT_MAX;
    int m = 0;
    int p = 0;

    for (auto a : events) {
      int b = a[0];
      int t = a[1];
      if (t - p >= m) {
        if (t - p == m) {
          ans = ans < b ? ans : b; // min(ans, b);
        } else {
          ans = b;
        }
        m = t - p;
      }
      p = t;
    }

    return ans;
  }
};
