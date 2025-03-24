class Solution {
public:
  int maxContainers(int n, int w, int maxWeight) {
    // N*N*W <= MW
    // MW / W - no. of containers max
    int possible = maxWeight / w;
    int all = n * n;
    if (all > possible)
      return possible;
    return all;
  }
};
