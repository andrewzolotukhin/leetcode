class Solution {
public:
  int maxRemoval(vector<int> &nums, vector<vector<int>> &queries) {
    sort(queries.begin(), queries.end());
    int n = nums.size();
    vector<int> diff(n + 1, 0);

    priority_queue<int> pq;
    int res = 0;
    int j = 0;
    for (int i = 0; i < n; i++) {
      res += diff[i];

      while (j < queries.size() && queries[j][0] == i) {
        pq.push(queries[j][1]);
        j++;
      }

      while (res < nums[i] && !pq.empty() && pq.top() >= i) {
        res++;
        diff[pq.top() + 1]--;
        pq.pop();
      }

      if (res < nums[i])
        return -1;
    }

    return pq.size();
  }
};
