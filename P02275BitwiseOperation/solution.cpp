class Solution {
public:
  int largestCombination(vector<int> &candidates) {
    vector<int> bc(25, 0);
    for (int i = 0; i < 25; i++) {
      for (int n : candidates) {
        if ((n & (1 << i)) != 0)
          bc[i]++;
      }
    }

    int ans = -1;
    for (int i = 0; i < 25; i++) {
      if (bc[i] > ans) {
        ans = bc[i];
      }
    }

    return ans;
  }
};
