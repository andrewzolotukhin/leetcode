class Solution {
public:
  vector<int> findSmallestSetOfVertices(int n, vector<vector<int>> &edges) {
    vector<int> inbound(n);

    for (auto e : edges) {
      inbound[e[1]]++;
    }

    vector<int> ans;

    for (int i = 0; i < n; i++) {
      if (inbound[i])
        continue;
      ans.push_back(i);
    }

    return ans;
  }
};
