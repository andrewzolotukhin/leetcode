class Solution {
public:
  int countBalancedPermutations(string num) {
    int mod = int(1e9) + 7;
    int n = num.size();
    unordered_map<int, int> freq;
    for (char c : num)
      freq[(int)(c - '0')]++;

    int sum = 0;
    for (int i = 1; i <= 9; i++) {
      sum += i * freq[i];
    }
    if (sum % 2)
      return 0;

    int evenCount = num.size() / 2;
    int oddCount = num.size() - evenCount;
    int half = sum / 2;

    vector<vector<long long>> combinations(
        oddCount + 1, vector<long long>(oddCount + 1, 0LL));

    for (int i = 0; i <= oddCount; i++) {
      combinations[i][i] = combinations[i][0] = 1;
      for (int k = 1; k < i; k++) {
        combinations[i][k] =
            (combinations[i - 1][k] + combinations[i - 1][k - 1]) % mod;
      }
    }

    vector<vector<long long>> dp(sum + 1, vector<long long>(oddCount + 1));
    dp[0][0] = 1;

    int currentSum = 0;
    int totalSum = 0;

    for (int i = 0; i <= 9; i++) {
      currentSum += freq[i];
      totalSum += i * freq[i];
      for (int odd = min(currentSum, oddCount);
           odd >= max(0, currentSum - (n - oddCount)); odd--) {
        auto even = currentSum - odd;

        for (int curr = min(totalSum, half); curr >= max(0, totalSum - half);
             curr--) {
          long long ans = 0;
          for (int j = max(0, freq[i] - even);
               j <= min(freq[i], odd) && i * j <= curr; j++) {
            long long w =
                (combinations[odd][j] * combinations[even][freq[i] - j]) % mod;
            ans = (ans + w * dp[curr - i * j][odd - j]) % mod;
          }
          dp[curr][odd] = ans % mod;
        }
      }
    }

    return dp[half][oddCount];
  }
};
