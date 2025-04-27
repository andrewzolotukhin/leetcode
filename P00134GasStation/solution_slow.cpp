class Solution {
public:
  int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    // 0
    // -2, -2, -2, 3, 3
    // -2  -4  -6  -3 0

    int n = gas.size();
    if (n == 1)
      return (gas[0] - cost[0] >= 0) ? 0 : -1;

    for (int i = 0; i < 2 * n; i++) {
      int index = i % n;
      if (gas[index] == cost[index])
        continue;
      int g = gas[index] - cost[index];
      index++;
      while (g >= 0 && index - i < n) {
        g += gas[index % n] - cost[index % n];
        index++;
      }
      if (index - i == n && g >= 0) {
        // while((cost[index + n - 1)])
        return i % n;
      } else {
        index += (index - i - 1);
      }
    }
    return -1;

    // 1 -3 1 -2 3
    // 1 -2 -1 -3 1
  }
};
