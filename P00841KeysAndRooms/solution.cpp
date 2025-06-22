class Solution {
public:
  bool canVisitAllRooms(vector<vector<int>> &rooms) {
    int n = rooms.size();
    set<int> visited = {0};

    queue<int> q;
    for (auto x : rooms[0])
      q.push(x);

    while (!q.empty()) {
      auto curr = q.front();
      q.pop();
      if (visited.count(curr))
        continue;

      visited.insert(curr);
      for (auto x : rooms[curr]) {
        if (!visited.count(x))
          q.push(x);
      }
    }

    return visited.size() == n;
  }
};
