class Solution {
public:
  bool checkPowersOfThree(int n) {

    while (n) {
      int r = n % 3;
      if (r != 1 && r != 0)
        return false;
      n /= 3;
    }

    return true;
  }
};
