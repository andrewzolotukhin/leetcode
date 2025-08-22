class Solution {
private:
  int find(int node, vector<int> &parents) {
    if (parents[node] == -1)
      return node;
    return parents[node] = find(parents[node], parents);
  }
  void join(int n1, int n2, vector<int> &parents) {
    int p1 = find(n1, parents);
    int p2 = find(n2, parents);
    if (p1 == p2)
      return;
    parents[p1] = p2;
  }

public:
  bool validPath(int n, vector<vector<int>> &edges, int source,
                 int destination) {
    vector<int> parents(n, -1);

    for (int i = 0; i < edges.size(); i++) {
      join(edges[i][0], edges[i][1], parents);
    }

    return find(source, parents) == find(destination, parents);
  }
};
