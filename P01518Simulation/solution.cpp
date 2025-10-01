class Solution {
public:
  int numWaterBottles(int numBottles, int numExchange) {
    int ans = 0;
    int empty = 0;

    while (numBottles) {
      numBottles--;
      ans++;
      empty++;
      if (empty == numExchange) {
        numBottles++;
        empty = 0;
      }
    }

    return ans;
  }
};
