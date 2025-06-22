class Solution {
private:
  int find(int i, vector<int> &parent) {
    if (parent[i] == i)
      return i;
    return parent[i] = find(parent[i], parent);
  }
  void merge(int v1, int v2, vector<int> &parent) {
    int g1 = find(v1, parent);
    int g2 = find(v2, parent);
    if (g1 == g2)
      return;

    parent[g1] = g2;
  }

public:
  int findCircleNum(vector<vector<int>> &isConnected) {
    int n = isConnected.size();
    vector<int> parent(n);
    for (int i = 0; i < n; i++)
      parent[i] = i;

    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (isConnected[i][j]) {
          merge(i, j, parent);
        }
      }
    }

    set<int> groups;
    for (int i = 0; i < n; i++) {
      groups.insert(find(i, parent));
    }

    return groups.size();
  }
};
