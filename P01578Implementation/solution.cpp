class Solution {
public:
  int minCost(string colors, vector<int> &neededTime) {
    int n = colors.size(), ans = 0;

    int prevC = colors[0], maxT = neededTime[0], s = maxT, c = 0;
    for (int i = 1; i < n; i++) {
      if (colors[i] == prevC) {
        s += neededTime[i];
        maxT = max(maxT, neededTime[i]);
        c++;
      } else {
        if (c) {
          ans += s - maxT;
        }
        c = 0;
        prevC = colors[i];
        maxT = s = neededTime[i];
      }
    }
    if (c) {
      ans += s - maxT;
    }
    return ans;
  }
};
