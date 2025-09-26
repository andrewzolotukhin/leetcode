class Solution {
private:
  void solve(int v, vector<vector<int>> &graph, unordered_set<int> &visited,
             vector<int> &path, vector<vector<int>> &ans) {
    if (v == graph.size() - 1) {
      ans.push_back(path);
      return;
    }

    for (auto n : graph[v]) {
      if (visited.count(n))
        continue;
      visited.insert(n);
      path.push_back(n);
      solve(n, graph, visited, path, ans);
      path.pop_back();
      visited.erase(n);
    }
  }

public:
  vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph) {
    unordered_set<int> visited = {0};
    vector<vector<int>> ans;

    vector<int> path = {0};
    solve(0, graph, visited, path, ans);

    return ans;
  }
};
