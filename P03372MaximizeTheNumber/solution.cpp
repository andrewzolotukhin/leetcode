class Solution {
private:
  int findNumberOfNodes(int node, int p, vector<vector<int>> &graph, int dist) {
    if (dist < 0) {
      return 0;
    }

    int ans = 1;
    for (int i = 0; i < graph[node].size(); i++) {
      if (graph[node][i] == p)
        continue;
      ans += findNumberOfNodes(graph[node][i], node, graph, dist - 1);
    }
    return ans;
  }

public:
  vector<int> maxTargetNodes(vector<vector<int>> &edges1,
                             vector<vector<int>> &edges2, int k) {
    int n = edges1.size() + 1, m = edges2.size() + 1;
    vector<int> cnt1(n, 0), cnt2(m, 0);
    vector<vector<int>> graph1(n, vector<int>());
    vector<vector<int>> graph2(m, vector<int>());

    for (auto e : edges1) {
      graph1[e[0]].push_back(e[1]);
      graph1[e[1]].push_back(e[0]);
    }

    for (auto e : edges2) {
      graph2[e[0]].push_back(e[1]);
      graph2[e[1]].push_back(e[0]);
    }

    for (int i = 0; i < n; i++) {
      cnt1[i] = findNumberOfNodes(i, -1, graph1, k);
    }
    int maxCnt2 = INT_MIN;
    for (int i = 0; i < m; i++) {
      cnt2[i] = findNumberOfNodes(i, -1, graph2, k - 1);
      if (cnt2[i] > maxCnt2) {
        maxCnt2 = cnt2[i];
      }
    }

    for (int i = 0; i < n; i++) {
      cnt1[i] += maxCnt2;
    }

    return cnt1;
  }
};
