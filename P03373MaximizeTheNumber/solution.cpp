class Solution {
private:
  int findNodes(vector<vector<int>> &tree, int node, int parent, int order,
                vector<int> &color) {
    int n = tree.size() + 1;
    int ans = 1 - order % 2;
    color[node] = order % 2;
    for (auto v : tree[node]) {
      if (v == parent)
        continue;
      ans += findNodes(tree, v, node, order + 1, color);
    }

    return ans;
  }

public:
  vector<int> maxTargetNodes(vector<vector<int>> &edges1,
                             vector<vector<int>> &edges2) {
    int n = edges1.size() + 1, m = edges2.size() + 1;
    vector<vector<int>> tree1(n, vector<int>()), tree2(m, vector<int>());

    for (auto &e : edges1) {
      tree1[e[0]].push_back(e[1]);
      tree1[e[1]].push_back(e[0]);
    }
    for (auto &e : edges2) {
      tree2[e[0]].push_back(e[1]);
      tree2[e[1]].push_back(e[0]);
    }

    vector<int> color1(n);
    vector<int> color2(m);
    auto r1 = findNodes(tree1, 0, -1, 0, color1);
    int r11 = n - r1;
    auto r2 = findNodes(tree2, 0, -1, 0, color2);
    int r21 = m - r2;

    vector<int> ans(n, 0);

    for (int i = 0; i < n; i++) {
      ans[i] = (color1[i] ? r11 : r1) + (r2 > r21 ? r2 : r21);
    }

    return ans;
  }
};
