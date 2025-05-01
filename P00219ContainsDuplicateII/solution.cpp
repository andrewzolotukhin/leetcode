class Solution {
public:
  bool containsNearbyDuplicate(vector<int> &nums, int k) {
    auto comp = [&](pair<int, int> a, pair<int, int> b) {
      if (a.first == b.first)
        return a.second > b.second;
      return a.first < b.first;
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> pq(
        comp);
    for (int i = 0; i < nums.size(); i++) {
      pq.push({nums[i], i});
    }

    int lastV = pq.top().first;
    int lastI = pq.top().second;
    pq.pop();
    while (!pq.empty()) {
      int cV = pq.top().first;
      int cI = pq.top().second;
      pq.pop();
      if (cV != lastV) {
        lastV = cV;
        lastI = cI;
        continue;
      }
      if (cI - lastI <= k)
        return true;
      lastI = cI;
    }

    return false;
  }
};
