class Solution {
public:
  int totalFruit(vector<int> &fruits) {
    vector<pair<int, int>> b;
    int i = 0, n = fruits.size();
    while (i < n) {
      int s = 1;
      int v = fruits[i++];
      while (i < n && fruits[i] == fruits[i - 1]) {
        i++;
        s++;
      }

      b.push_back({s, v});
    }

    if (b.size() == 1)
      return b[0].first;
    int ans = b[0].first + b[1].first;
    if (b.size() == 2)
      return ans;

    int acc = ans;
    for (i = 2; i < b.size(); i++) {
      if (b[i].second == b[i - 2].second) {
        acc += b[i].first;
      } else {
        acc = b[i - 1].first + b[i].first;
      }
      ans = max(ans, acc);
    }
    return ans;
  }
};
