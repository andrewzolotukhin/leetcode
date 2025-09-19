class Solution {
public:
  vector<int> findIndices(vector<int> &nums, int indexDifference,
                          int valueDifference) {
    /*
     * It's a suboptimal way to solve this problem.
     * The correct one takes O(n) time.
     * We should just go through the array and track current min/max elements
     * and their indices. And on every iteration we check if the condition is
     * satisfied.
     */
    vector<pair<int, int>> p;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      p.push_back({nums[i], i});
    }

    sort(p.begin(), p.end());

    for (int i = 0; i < n; i++) {
      int s = p[i].first;
      int sIndex = p[i].second;
      int e = -1;
      int l = i, r = n - 1;
      while (l <= r) {
        int mid = (l + r) / 2;
        // cout << mid << ' ' << p[mid].first << ' ' << s << '\n';
        if (p[mid].first - s >= valueDifference) {
          e = mid;
          r = mid - 1;
        } else {
          l = mid + 1;
        }
      }
      if (e == -1)
        continue;
      for (int j = e; j < n; j++) {
        if (abs(p[j].second - sIndex) >= indexDifference) {
          return {sIndex, p[j].second};
        }
      }
    }

    return {-1, -1};
  }
};
