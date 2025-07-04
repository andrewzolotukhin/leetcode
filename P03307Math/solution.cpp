class Solution {
public:
  char kthCharacter(long long k, vector<int> &operations) {
    int ans = 0;
    int i;
    while (k != 1) {
      i = __lg(k);

      if ((1LL << i) == k) {
        i--;
      }

      k -= 1LL << i;
      if (operations[i]) {
        ans++;
      }
    }

    return 'a' + (ans % 26);
  }
};
