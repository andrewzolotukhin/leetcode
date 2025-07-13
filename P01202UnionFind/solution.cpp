class Solution {
private:
  int find(int a, vector<int> &parent) {
    if (parent[a] == a)
      return a;
    return parent[a] = find(parent[a], parent);
  }
  void join(int a, int b, vector<int> &parent) {
    if (a == b)
      return;
    int pa = find(a, parent);
    int pb = find(b, parent);
    if (pa == pb)
      return;
    parent[pa] = pb;
  }

public:
  string smallestStringWithSwaps(string s, vector<vector<int>> &pairs) {

    int n = s.size();
    vector<int> parent(n, -1);

    for (int i = 0; i < n; i++) {
      parent[i] = i;
    }

    for (auto pair : pairs) {
      join(pair[0], pair[1], parent);
    }

    unordered_map<int, string> m;

    for (int i = 0; i < n; i++) {
      m[find(i, parent)] += s[i];
    }

    for (auto [k, v] : m) {
      sort(m[k].begin(), m[k].end());
    }

    unordered_map<int, int> idx;

    for (int i = 0; i < n; i++) {
      auto p = find(i, parent);
      if (idx[p] == m[p].size())
        continue;
      s[i] = m[p][idx[p]++];
    }

    return s;
  }
};
