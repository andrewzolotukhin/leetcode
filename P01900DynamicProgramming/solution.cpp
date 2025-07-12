class Solution {
private:
  int L[30][30][30], R[30][30][30];
  pair<int, int> solve(int n, int l, int r) {
    if (L[n][l][r])
      return {L[n][l][r], R[n][l][r]};

    if (l + r == n + 1) {
      return {1, 1};
    }

    if (l + r > n + 1) {
      auto rr = solve(n, n + 1 - r, n + 1 - l);
      L[n][l][r] = rr.first;
      R[n][l][r] = rr.second;
      return rr;
    }

    int ansS = INT_MAX, ansB = INT_MIN;
    int gmid = (n + 1) / 2;

    if (r <= gmid) {
      for (int i = 0; i < l; i++) {
        for (int j = 0; j < r - l; j++) {
          auto [x, y] = solve(gmid, i + 1, i + j + 2);
          ansS = min(ansS, x);
          ansB = max(ansB, y);
        }
      }
    } else {
      int rp = n + 1 - r;
      int mid = (n - 2 * rp + 1) / 2;

      for (int i = 0; i < l; i++) {
        for (int j = 0; j < rp - l; j++) {
          auto [x, y] = solve(gmid, i + 1, i + j + mid + 2);
          ansS = min(ansS, x);
          ansB = max(ansB, y);
        }
      }
    }

    L[n][l][r] = ansS + 1;
    R[n][l][r] = ansB + 1;

    return {L[n][l][r], R[n][l][r]};
  }

public:
  vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
    if (firstPlayer > secondPlayer) {
      swap(firstPlayer, secondPlayer);
    }
    memset(L, 0, sizeof(L));
    memset(R, 0, sizeof(R));
    auto [l, r] = solve(n, firstPlayer, secondPlayer);
    return {l, r};
  }
};
