class Solution {
public:
  long long totalCost(vector<int> &costs, int k, int candidates) {
    int n = costs.size(), l = 0, r = n - 1;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    long long ans = 0;

    for (int i = 0; i < candidates; i++) {
      pq.push({costs[l], l});
      l++;
    }

    for (int i = 0; i < candidates && r >= l; i++) {
      pq.push({costs[r], r});
      r--;
    }

    while (k) {
      auto curr = pq.top();
      pq.pop();

      ans += curr.first;
      // cout << curr.first << ' ' << r << '\n';
      k--;

      if (l > r)
        continue;
      if (curr.second >= r) {
        // cout << "addingR: " << costs[r] << '\n';
        pq.push({costs[r], r});
        r--;
      } else {
        // cout << "addingL: " << costs[l] << '\n';
        pq.push({costs[l], l});
        l++;
      }
    }

    return ans;
  }
};
