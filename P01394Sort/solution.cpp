class Solution {
public:
  int findLucky(vector<int> &arr) {
    map<int, int> m;
    for (auto a : arr)
      m[a]++;

    int ans = -1;
    for (auto [k, v] : m) {
      if (k == v)
        ans = v;
    }
    return ans;
  }
};
