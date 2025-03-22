#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
  int find(vector<int> &parents, int v) {
    if (parents[v] == -1)
      return v;

    parents[v] = find(parents, parents[v]);
    return parents[v];
  }
  void Union(vector<int> &parents, int v1, int v2) {
    int pv1 = find(parents, v1);
    int pv2 = find(parents, v2);
    if (pv1 == pv2)
      return;

    parents[pv2] = pv1;
  }

public:
  vector<int> minimumCost(int n, vector<vector<int>> &edges,
                          vector<vector<int>> &queries) {
    vector<int> parents(n, -1);
    vector<unsigned int> componentCost(n, (unsigned int)(-1));

    for (auto edge : edges) {
      int f = edge[0];
      int t = edge[1];
      int c = edge[2];
      Union(parents, f, t);
      int component = find(parents, f);
      componentCost[component] &= c;
    }

    vector<int> ans(queries.size());
    for (int q = 0; q < queries.size(); q++) {
      int c1 = find(parents, queries[q][0]);
      int c2 = find(parents, queries[q][1]);
      ans[q] = (c1 == c2) ? componentCost[c1] : -1;
    }

    return ans;
  }
};
