class Solution {
public:
  bool hasGroupsSizeX(vector<int> &deck) {
    unordered_map<int, int> m;
    for (const auto &v : deck)
      m[v]++;

    int pv = m[deck[0]];

    for (const auto &[k, v] : m) {
      if (pv < 2)
        return false;
      pv = gcd(pv, v);
    }
    return pv > 1;
  }
};
