class Solution {
public:
  bool canPlaceFlowers(vector<int> &flowerbed, int n) {
    if (n == 0)
      return true;
    if (flowerbed.size() == 1)
      return flowerbed[0] == 0 ? (n <= 1) : (n == 0);
    if (flowerbed.size() >= 2 && flowerbed[0] == 0 && flowerbed[1] == 0) {
      flowerbed[0] = 1;
      n--;
    }
    if (n == 0)
      return true;
    if (flowerbed.size() >= 3 && flowerbed[flowerbed.size() - 1] == 0 &&
        flowerbed[flowerbed.size() - 2] == 0) {
      flowerbed[flowerbed.size() - 1] = 1;
      n--;
    }

    int i = 0;
    while (n && i < (int)flowerbed.size() - 3) {
      if (flowerbed[i] == 0 && flowerbed[i + 1] == 0 && flowerbed[i + 2] == 0) {
        n--;
        flowerbed[i + 1] = 1;
      }
      i++;
    }

    return n == 0;
  }
};
