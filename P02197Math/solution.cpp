class Solution {
public:
  vector<int> replaceNonCoprimes(vector<int> &nums) {
    list<int> list(nums.begin(), nums.end());

    for (auto t = list.begin(); t != list.end(); t++) {
      if (t == list.begin())
        continue;
      int v1 = *prev(t);
      int v2 = *t;
      int cd = gcd(v1, v2);
      if (cd != 1) {
        list.erase(prev(t));
        *t = (long long)v1 * v2 / cd;
        t--;
      }
    }
    vector<int> ans(list.begin(), list.end());
    return ans;
  }
};
