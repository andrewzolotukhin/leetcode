class Solution {
public:
  int maxEvents(vector<vector<int>> &events) {
    sort(events.begin(), events.end());
    int n = events.size();
    int ans = 0;
    int endDay = -1;
    for (int i = 0; i < n; i++) {
      if (events[i][1] > endDay)
        endDay = events[i][1];
    }

    priority_queue<int, vector<int>, greater<>> pq;

    int j = 0;
    for (int i = 0; i <= endDay; i++) {
      while (j < n && events[j][0] <= i) {
        pq.push(events[j][1]);
        j++;
      }

      while (!pq.empty() && pq.top() < i) {
        pq.pop();
      }

      if (!pq.empty()) {
        pq.pop();
        ans++;
      }
    }

    return ans;
  }
};
