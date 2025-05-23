class Solution {
public:
  vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2,
                                     int k) {

    auto comparer = [&](vector<int> &a, vector<int> &b) {
      return ((long long)nums1[a[0]] + (long long)nums2[a[1]]) >
             ((long long)nums1[b[0]] + (long long)nums2[b[1]]);
    };
    priority_queue<vector<int>, vector<vector<int>>, decltype(comparer)> pq(
        comparer);

    vector<vector<int>> ans;
    pq.push({0, 0});
    int n = nums1.size(), m = nums2.size();
    set<pair<int, int>> visited;
    visited.insert({0, 0});

    while (k--) {
      auto p = pq.top();
      pq.pop();
      int l = p[0];
      int r = p[1];
      ans.push_back({nums1[l], nums2[r]});

      if (l + 1 < n && visited.find({l + 1, r}) == visited.end()) {
        pq.push({l + 1, r});
        visited.insert({l + 1, r});
      }

      if (r + 1 < m && visited.find({l, r + 1}) == visited.end()) {
        pq.push({l, r + 1});
        visited.insert({l, r + 1});
      }
    }

    return ans;
  }
};
