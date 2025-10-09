class Solution {
public:
  vector<string> buildArray(vector<int> &target, int n) {
    vector<string> ans;

    int t = 0, v = 1;

    while (t < target.size() && v <= n) {
      int tv = target[t];
      if (v < tv) {
        ans.push_back("Push");
        ans.push_back("Pop");
        v++;
        continue;
      }

      if (v == tv) {
        ans.push_back("Push");
        v++;
        t++;
        continue;
      }
    }

    return ans;
  }
};
