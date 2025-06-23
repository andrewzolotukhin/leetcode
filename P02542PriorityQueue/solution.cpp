class Solution {
public:
  long long maxScore(vector<int> &nums1, vector<int> &nums2, int k) {
    int n = nums1.size();

    vector<pair<int, int>> nums(n);
    for (int i = 0; i < n; i++)
      nums[i] = {nums2[i], nums1[i]};

    sort(nums.rbegin(), nums.rend());
    long long total = 0, ans = 0;
    priority_queue<int, vector<int>, greater<>> pq;

    for (int i = 0; i < nums.size(); i++) {
      pq.push(nums[i].second);
      total += nums[i].second;
      if (pq.size() > k) {
        total -= pq.top();
        pq.pop();
      }
      if (pq.size() == k) {
        ans = max(ans, total * nums[i].first);
      }
    }
    return ans;
  }
};
