class Solution {
public:
  int smallestRepunitDivByK(int k) {
    // n mod k = 0
    // n mod 10 = 1

    int rem = 1, ans = 1;
    unordered_set<int> seen = {1};

    while (rem % k != 0) {
      int n = rem * 10 + 1;
      rem = n % k;
      if (seen.count(rem)) {
        return -1;
      }
      seen.insert(rem);
      ans++;
    }

    return ans;
  }
};
