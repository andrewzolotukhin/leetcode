class Solution {
public:
  int largestPathValue(string colors, vector<vector<int>> &edges) {
    int n = colors.size(), m = edges.size();
    unordered_map<int, vector<int>> graph;
    vector<int> indegree(n, 0);

    for (auto &edge : edges) {
      graph[edge[0]].push_back(edge[1]);
      indegree[edge[1]]++;
    }

    queue<int> q;
    vector<vector<int>> count(n, vector<int>(26, 0));

    for (int i = 0; i < n; i++) {
      if (indegree[i] == 0) {
        q.push(i);
        count[i][colors[i] - 'a'] = 1;
      }
    }

    int ans = 0;
    int vertexesProcessed = 0;

    while (q.size()) {
      auto curr = q.front();
      q.pop();

      int maxCount = 0;
      for (int i = 0; i < 26; i++) {
        if (count[curr][i] > maxCount)
          maxCount = count[curr][i];
      }

      if (maxCount > ans) {
        ans = maxCount;
      }
      vertexesProcessed++;

      for (int i = 0; i < graph[curr].size(); i++) {
        int next = graph[curr][i];
        for (int j = 0; j < 26; j++) {
          count[next][j] =
              max(count[next][j], count[curr][j] + (j == colors[next] - 'a'));
        }
        if (--indegree[graph[curr][i]] == 0) {
          q.push(graph[curr][i]);
        }
      }
    }

    return vertexesProcessed != n ? -1 : ans;
  }
};
