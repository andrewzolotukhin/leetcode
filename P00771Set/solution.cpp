class Solution {
public:
  int numJewelsInStones(string jewels, string stones) {
    unordered_set<char> j;
    for (char c : jewels)
      j.insert(c);

    int ans = 0;
    for (auto c : stones)
      ans += j.count(c);

    return ans;
  }
};
