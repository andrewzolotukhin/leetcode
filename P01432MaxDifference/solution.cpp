class Solution {
public:
  int maxDiff(int num) {
    int ansMin = num, ansMax = num;
    vector<int> dec;
    while (num) {
      dec.push_back(num % 10);
      num /= 10;
    }

    auto trySwap = [&](int r1, int r2) {
      int ans = 0;
      if (r2 == 0 && dec[dec.size() - 1] == r1)
        return;
      for (int i = dec.size() - 1; i >= 0; i--) {
        ans *= 10;
        ans += ((dec[i] == r1) ? r2 : dec[i]);
      }
      if (ans == 0)
        return;

      ansMin = min(ans, ansMin);
      ansMax = max(ans, ansMax);
    };

    for (int i = 0; i <= 9; i++) {
      for (int j = 0; j <= 9; j++) {
        if (i == j)
          continue;
        trySwap(i, j);
      }
    }

    return ansMax - ansMin;
  }
};
