class Solution {
public:
  vector<int> productQueries(int n, vector<vector<int>> &queries) {
    int mod = int(1e9) + 7;

    vector<int> powers;

    for (int i = 1; i <= n; i <<= 1) {
      if (i & n) {
        powers.push_back(i);
      }
    }

    vector<vector<int>> muls(powers.size(), vector<int>(powers.size(), 1));
    for (int i = 0; i < powers.size(); i++) {
      unsigned long long int product = 1;
      for (int j = i; j < powers.size(); j++) {
        product = (product * powers[j]) % mod;
        muls[i][j] = (int)product;
      }
    }

    vector<int> ans;
    for (auto q : queries) {
      int l = q[0];
      int r = q[1];

      ans.push_back(muls[l][r]);
    }

    return ans;
  }
};
