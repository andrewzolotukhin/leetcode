class Solution {
public:
  int numOfSubarrays(vector<int> &arr) {
    int result = 0;
    int mod = 1e9 + 7;

    int n = arr.size();

    vector<int> dpE(n, 0), dpO(n, 0);

    if (arr[0] & 1) {
      dpO[0] = 1;
    } else {
      dpE[0] = 1;
    }

    result += dpO[0];

    for (int i = 1; i < n; i++) {
      if (arr[i] & 1) {
        // odd
        dpO[i] = (dpE[i - 1] + 1) % mod;
        dpE[i] = dpO[i - 1];
      } else {
        dpO[i] = dpO[i - 1];
        dpE[i] = (dpE[i - 1] + 1) % mod;
      }

      result = (result + dpO[i]) % mod;
    }
    return result;
  }
};
