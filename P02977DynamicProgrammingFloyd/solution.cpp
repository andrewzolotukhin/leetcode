struct Trie {
  Trie *child[26];
  int id;

  Trie() {
    for (int i = 0; i < 26; i++) {
      child[i] = nullptr;
    }
    id = -1;
  }
};

int add(Trie *node, const string &input, int &index) {
  for (char c : input) {
    int i = c - 'a';
    if (!node->child[i]) {
      node->child[i] = new Trie();
    }
    node = node->child[i];
  }

  if (node->id == -1) {
    node->id = ++index;
  }

  return node->id;
}

void update(long long &x, long long y) {
  if (x == -1 || y < x) {
    x = y;
  }
}

class Solution {
public:
  long long minimumCost(string source, string target, vector<string> &original,
                        vector<string> &changed, vector<int> &cost) {
    int n = source.size(), m = original.size();
    Trie *root = new Trie();

    int p = -1;
    vector<vector<int>> dist(m * 2, vector<int>(m * 2, INT_MAX / 2));
    for (int i = 0; i < m * 2; i++) {
      dist[i][i] = 0;
    }
    for (int i = 0; i < m; i++) {
      int a = add(root, original[i], p);
      int b = add(root, changed[i], p);
      dist[a][b] = min(dist[a][b], cost[i]);
    }

    for (int k = 0; k <= p; k++) {
      for (int i = 0; i <= p; i++) {
        for (int j = 0; j <= p; j++) {
          dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        }
      }
    }

    vector<long long> ans(n, -1);

    for (int i = 0; i < n; i++) {
      if (i > 0 && ans[i - 1] == -1)
        continue;

      long long b = (i == 0 ? 0 : ans[i - 1]);
      if (source[i] == target[i]) {
        update(ans[i], b);
      }

      Trie *u = root;
      Trie *v = root;
      for (int j = i; j < n; j++) {
        u = u->child[source[j] - 'a'];
        v = v->child[target[j] - 'a'];
        if (!u || !v)
          break;
        if (u->id != -1 && v->id != -1 && dist[u->id][v->id] != INT_MAX / 2) {
          update(ans[j], b + dist[u->id][v->id]);
        }
      }
    }

    return ans[n - 1];
  }
};
