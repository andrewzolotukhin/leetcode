class Solution {
public:
  vector<int> minimumCost(int n, vector<vector<int>> &edges,
                          vector<vector<int>> &queries) {
    vector<int> components(n, -1);
    vector<int> depth(n, 0);

    vector<unsigned int> componentCost(n, -1);

    for (auto &edge : edges) {
      Union(components, depth, edge[0], edge[1]);
    }

    for (auto &edge : edges) {
      int root = find(components, edge[0]);
      componentCost[root] &= edge[2];
    }

    vector<int> answer;
    for (auto &query : queries) {
      int start = query[0];
      int end = query[1];

      // If the two nodes are in different connected components, return -1
      if (find(components, start) != find(components, end)) {
        answer.push_back(-1);
      } else {
        int root = find(components, start);
        answer.push_back(componentCost[root]);
      }
    }
    return answer;
  }

private:
  int find(vector<int> &components, int node) {
    if (components[node] == -1)
      return node;
    return components[node] = find(components, components[node]);
  }

  void Union(vector<int> &components, vector<int> &depth, int node1,
             int node2) {
    int root1 = find(components, node1);
    int root2 = find(components, node2);
    if (root1 == root2)
      return;
    if (depth[root1] < depth[root2])
      swap(root1, root2);
    components[root2] = root1;
    if (depth[root1] == depth[root2])
      depth[root1]++;
  }
};
