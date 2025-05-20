class Solution {
private:
  int solve(vector<int> &adj) {
    int n = adj.size();

    queue<pair<int, int>> pq;
    pq.push({0, 0});

    vector<bool> visited(n, false);
    visited[0] = true;

    while (!pq.empty()) {
      auto curr = pq.front();
      pq.pop();
      auto index = curr.second;
      auto length = curr.first;

      if (index == n - 1) {
        return length;
      }

      for (int i = index + 1; (i <= n - 1) && i <= index + 6; i++) {
        if (adj[i] != -1) {
          if (!visited[adj[i]]) {
            pq.push({length + 1, adj[i]});
            visited[adj[i]] = true;
          }
        } else {
          if (!visited[i]) {
            pq.push({length + 1, i});
            visited[i] = true;
          }
        }
      }
    }

    return -1;
  }

public:
  int snakesAndLadders(vector<vector<int>> &board) {
    int n = board.size();
    int total = n * n;

    vector<int> adj(total, -1);

    bool inv = true;
    for (int i = 0; i < total; i++) {
      int row = n - 1 - i / n;
      int c = i % n;
      if (c == 0)
        inv = !inv;
      int col = inv ? (n - 1 - i % n) : (i % n);

      if (board[row][col] != -1) {
        adj[i] = board[row][col] - 1;
      }
    }

    return solve(adj);
  }
};
