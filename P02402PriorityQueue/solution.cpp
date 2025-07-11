class Solution {
public:
  int mostBooked(int n, vector<vector<int>> &meetings) {
    sort(meetings.begin(), meetings.end());

    priority_queue<int, vector<int>, greater<>> freeRooms;
    for (int i = 0; i < n; i++) {
      freeRooms.push(i);
    }

    priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                   greater<pair<long long, int>>>
        nextFree;
    vector<int> freq(n, 0);
    for (int meeting = 0; meeting < meetings.size(); meeting++) {
      auto start = meetings[meeting][0];
      auto end = meetings[meeting][1];
      while (!nextFree.empty() && nextFree.top().first <= start) {
        auto nf = nextFree.top().second;
        freeRooms.push(nf);
        nextFree.pop();
      }
      if (freeRooms.empty()) {
        auto [av, room] = nextFree.top();
        nextFree.pop();
        nextFree.push({av + end - start, room});
        freq[room]++;
      } else {
        auto room = freeRooms.top();
        freq[room]++;
        freeRooms.pop();
        nextFree.push({end, room});
      }
    }

    int ans = -1;
    int v = -1;
    for (int i = 0; i < n; i++) {
      if (freq[i] > v) {
        v = freq[i];
        ans = i;
      }
    }

    return ans;
  }
};
