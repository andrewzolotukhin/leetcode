class Solution {
private:
  bool isGood(int n) {
    while (n) {
      if (n % 10 == 0)
        return false;
      n /= 10;
    }
    return true;
  }

public:
  vector<int> getNoZeroIntegers(int n) {
    vector<int> ans;

    for (int i = 1; i <= n / 2; i++) {
      if (isGood(i) && isGood(n - i))
        return {i, n - i};
    }

    assert(false);
  }
};
