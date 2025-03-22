class Solution {
private:
  int find(vector<int> &parents, int v) {
    if (parents[v] == -1)
      return v;
    parents[v] = find(parents, parents[v]);
    return parents[v];
  }

  void Union(vector<int> &parents, int v1, int v2) {
    int p1 = find(parents, v1);
    int p2 = find(parents, v2);
    if (p1 == p2)
      return;

    parents[p2] = p1;
  }
  bool fullyConnected(int component, unordered_map<int, vector<int>> &vertexes,
                      vector<int> &parents, vector<vector<bool>> &isConnected) {
    for (auto v1 : vertexes[component]) {
      for (auto v2 : vertexes[component]) {
        if (v1 == v2)
          continue;
        if (!isConnected[v1][v2])
          return false;
      }
    }

    return true;
  }

public:
  int countCompleteComponents(int n, vector<vector<int>> &edges) {
    vector<int> parents(n, -1);

    vector<vector<bool>> connected(n, vector<bool>(n, false));
    for (int i = 0; i < edges.size(); i++) {
      connected[edges[i][0]][edges[i][1]] = true;
      connected[edges[i][1]][edges[i][0]] = true;
      Union(parents, edges[i][0], edges[i][1]);
    }

    set<int> processed;
    int ans = 0;

    unordered_map<int, vector<int>> vertexes;
    for (int i = 0; i < n; i++) {
      int c = find(parents, i);
      vertexes[c].push_back(i);
    }

    for (int i = 0; i < n; i++) {
      int c = find(parents, i);
      if (processed.count(c))
        continue;

      if (fullyConnected(c, vertexes, parents, connected)) {
        ans++;
      }

      processed.insert(c);
    }

    return ans;
  }
};
