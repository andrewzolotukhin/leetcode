class Solution {
public:
  vector<int> processQueries(int c, vector<vector<int>> &connections,
                             vector<vector<int>> &queries) {
    vector<int> parent(c);
    for (int i = 0; i < c; i++)
      parent[i] = i;

    function<int(int)> find = [&](int a) {
      if (parent[a] == a)
        return a;
      return parent[a] = find(parent[a]);
    };

    auto join = [&](int a, int b) {
      int pa = find(a), pb = find(b);
      if (pa == pb)
        return;
      parent[pb] = pa;
    };

    for (auto &c : connections) {
      join(c[0] - 1, c[1] - 1);
    }

    vector<int> ans;

    unordered_set<int> offline;
    unordered_map<int, priority_queue<int, vector<int>, greater<int>>> groups;

    for (int i = 0; i < c; i++) {
      int g = find(i);
      groups[g].push(i);
    }

    for (auto &q : queries) {
      int g = find(q[1] - 1);
      if (q[0] == 1) {
        if (offline.count(q[1] - 1)) {
          while (!groups[g].empty() && offline.count(groups[g].top()))
            groups[g].pop();

          if (!groups[g].empty()) {
            int f = groups[g].top();
            ans.push_back(f + 1);
          } else {
            ans.push_back(-1);
          }
        } else {
          ans.push_back(q[1]);
        }
      } else {
        offline.insert(q[1] - 1);
      }
    }

    return ans;
  }
};
