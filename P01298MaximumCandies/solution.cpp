class Solution {
public:
  int maxCandies(vector<int> &status, vector<int> &candies,
                 vector<vector<int>> &keys, vector<vector<int>> &containedBoxes,
                 vector<int> &initialBoxes) {
    unordered_set<int> collected;
    int ans = 0;
    auto comp = [&](pair<int, int> &a, pair<int, int> &b) {
      return a.second < b.second;
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> q(
        comp);
    for (auto b : initialBoxes) {
      q.push({b, status[b]});
    }

    while (!q.empty()) {
      auto current = q.top();
      q.pop();
      int currentBox = current.first;
      if (collected.count(currentBox))
        continue;

      if (status[currentBox] == 0) {
        q.push({currentBox, status[currentBox]});
        if (q.top().first == currentBox && q.top().second == status[currentBox])
          break;
        continue;
      }

      ans += candies[currentBox];
      collected.insert(currentBox);

      for (auto nb : keys[currentBox]) {
        status[nb] = 1;
      }

      for (auto cb : containedBoxes[currentBox]) {
        q.push({cb, status[cb]});
      }
    }

    return ans;
  }
};
