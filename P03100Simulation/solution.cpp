class Solution {
public:
  int maxBottlesDrunk(int numBottles, int numExchange) {
    int ans = 0;
    int empty = 0;
    while (numBottles || empty >= numExchange) {
      if (empty >= numExchange) {
        empty -= numExchange;
        numExchange++;
        numBottles++;
      }
      if (numBottles) {
        empty += numBottles;
        ans += numBottles;
        numBottles = 0;
      }
    }

    return ans;
  }
};
