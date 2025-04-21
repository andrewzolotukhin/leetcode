class Solution {
public:
  int numberOfArrays(vector<int> &differences, int lower, int upper) {
    // 1 -3 4
    // 0 -> 0 1 -2 2
    // 1 -> 1 2 -1 3 -------
    // 2 -> 2 3 0 4  -------
    // 3 -> 3 4 1 5  +++++++
    // 4 -> 4 5 2 6  +++++++

    long long minVal = 0, maxVal = 0;
    long long prefix = 0;
    for (auto v : differences) {
      prefix += (long long)v;
      minVal = min(minVal, prefix);
      maxVal = max(maxVal, prefix);
    }

    long long start = lower - minVal;
    long long end = upper - maxVal;

    long long ans = end - start + 1;

    return (ans > 0) ? ans : 0;
  }
};
