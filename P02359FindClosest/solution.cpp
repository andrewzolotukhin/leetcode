class Solution {
public:
  int closestMeetingNode(vector<int> &edges, int node1, int node2) {
    int n = edges.size();

    int current = node1;
    vector<bool> visited(n, false);
    vector<int> maxD1(n, -1);
    int dist = 0;

    while (current != -1 && !visited[current]) {
      visited[current] = true;
      maxD1[current] = dist++;
      current = edges[current];
    }

    // cout << node2 << '\n';
    visited = vector<bool>(n, false);
    vector<int> maxD2(n, -1);
    dist = 0;
    current = node2;
    while (current != -1 && !visited[current]) {
      visited[current] = true;
      maxD2[current] = dist++;
      current = edges[current];
    }

    int ans = -1;
    int ansV = INT_MAX;

    for (int i = 0; i < n; i++) {
      if (maxD1[i] == -1 || maxD2[i] == -1)
        continue;
      int m = max(maxD1[i], maxD2[i]);
      if (m < ansV) {
        ans = i;
        ansV = m;
      }
    }

    return ans;
  }
};
