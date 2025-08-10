class Solution {
public:
  bool reorderedPowerOf2(int n) {
    vector<array<int, 10>> p2(30);
    for (int i = 0; i < 30; i++) {
      int p = 1 << i;
      while (p) {
        int d = p % 10;
        p2[i][d]++;
        p /= 10;
      }
    }

    array<int, 10> digits;
    while (n) {
      int d = n % 10;
      digits[d]++;
      n /= 10;
    }

    for (int i = 0; i < 30; i++) {
      bool ok = true;
      for (int j = 0; j < 10; j++) {
        if (p2[i][j] != digits[j]) {
          ok = false;
          break;
        }
      }
      if (ok)
        return true;
    }

    return false;
  }
};
