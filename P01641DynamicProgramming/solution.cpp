class Solution {
private:
  unordered_map<int, int> memo;
  int solve(int curr, int left) {
    int key = (left << 10) | curr;
    if (memo.count(key))
      return memo[key];
    if (left == 0) {
      return memo[key] = 1;
    }
    int i = 1;
    int ans = 0;
    while (i <= left) {
      for (int j = curr + 1; j < 6; j++) {
        ans += solve(j, left - i);
      }
      i++;
    }

    return memo[key] = ans;
  }

public:
  int countVowelStrings(int n) {
    memo = unordered_map<int, int>();
    return solve(0, n);
  }
};
