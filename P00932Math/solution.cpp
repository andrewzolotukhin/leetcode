class Solution {
public:
  vector<int> beautifulArray(int n) {
    vector<int> ans;
    ans.push_back(1);

    while (ans.size() < n) {
      vector<int> tmp;
      for (int i : ans)
        if (i * 2 - 1 <= n)
          tmp.push_back(i * 2 - 1);
      for (int i : ans)
        if (i * 2 <= n)
          tmp.push_back(i * 2);
      ans = tmp;
    }

    return ans;
  }
};
