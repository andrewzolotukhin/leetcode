class Solution {
private:
  int find(vector<int> &parents, int v) {
    if (parents[v] == -1)
      return v;
    parents[v] = find(parents, parents[v]);
    return parents[v];
  }
  void Union(vector<int> &parents, int v1, int v2) {
    auto p1 = find(parents, v1);
    auto p2 = find(parents, v2);
    if (p1 == p2)
      return;
    parents[p2] = p1;
  }

public:
  int numberOfComponents(vector<vector<int>> &properties, int k) {
    int n = properties.size();
    int m = properties[0].size();

    vector<set<int>> sets;

    for (int i = 0; i < n; i++) {
      sets.push_back(set<int>(properties[i].begin(), properties[i].end()));
    }

    vector<vector<int>> graph(n, vector<int>());
    vector<int> parents(n, -1);

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (i == j)
          continue;

        int common = 0;
        auto s1 = sets[i].begin();
        auto s2 = sets[j].begin();

        while (s1 != sets[i].end() && s2 != sets[j].end()) {
          if (*s1 == *s2) {
            common++;
            s1++;
            s2++;
          } else if (*s1 < *s2) {
            s1++;
          } else {
            s2++;
          }
        }

        if (common >= k) {
          graph[i].push_back(j);
          Union(parents, i, j);
        }
      }
    }

    set<int> components;

    for (int i = 0; i < n; i++) {
      components.insert(find(parents, i));
    }

    return components.size();
  }
};
