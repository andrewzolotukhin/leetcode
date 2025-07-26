class Solution {
public:
  int minCost(int maxTime, vector<vector<int>> &edges,
              vector<int> &passingFees) {
    int n = passingFees.size();

    vector<set<vector<int>>> state(n);
    vector<vector<pair<int, int>>> adj(n);

    for (auto &e : edges) {
      adj[e[0]].push_back({e[1], e[2]});
      adj[e[1]].push_back({e[0], e[2]});
    }

    priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;

    pq.push({passingFees[0], 0, 0});

    while (!pq.empty()) {
      auto curr = pq.top();
      pq.pop();
      int fee = curr[0];
      int time = curr[1];
      int city = curr[2];

      if (city == n - 1) {
        return fee;
      }

      for (auto neigh : adj[city]) {
        int nCity = neigh.first;
        int nTime = neigh.second;
        if (time + nTime <= maxTime) {
          auto it = state[nCity].upper_bound(
              {fee + passingFees[nCity], time + nTime});
          if (it == begin(state[nCity]) || (*prev(it))[1] > time + nTime) {
            state[nCity].insert({fee + passingFees[nCity], time + nTime});
            pq.push({fee + passingFees[nCity], time + nTime, nCity});
          }
        }
      }
    }
    return -1;
  }
};
