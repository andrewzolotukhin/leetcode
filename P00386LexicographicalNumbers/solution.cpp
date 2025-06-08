class Solution {
public:
  vector<int> lexicalOrder(int n) {
    vector<int> ans;
    int last = 1;
    while (ans.size() < n) {
      ans.push_back(last);
      if (last * 10 <= n) {
        last *= 10;
        continue;
      }
      while (last % 10 == 9 || last >= n) {
        last /= 10;
      }
      last += 1;
    }
    return ans;
  }
};
