class Solution {
public:
  vector<int> findAllPeople(int n, vector<vector<int>> &meetings,
                            int firstPerson) {
    unordered_map<int, vector<pair<int, int>>> adj;

    for (auto &meet : meetings) {
      int l = meet[0], r = meet[1], time = meet[2];
      adj[l].push_back({time, r});
      adj[r].push_back({time, l});
    }

    vector<int> dist(n, INT_MAX);
    dist[0] = 0;
    dist[firstPerson] = 0;

    queue<pair<int, int>> q;
    q.push({0, 0});
    q.push({firstPerson, 0});

    while (!q.empty()) {
      auto [p, t] = q.front();
      q.pop();

      for (auto [time, next] : adj[p]) {
        if (time >= t && dist[next] > time) {
          dist[next] = time;
          q.push({next, time});
        }
      }
    }

    vector<int> ans;
    for (int i = 0; i < n; i++) {
      if (dist[i] != INT_MAX)
        ans.push_back(i);
    }

    return ans;
  }
};
