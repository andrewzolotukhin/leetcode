class Solution {
public:
  vector<int> getFinalState(vector<int> &nums, int k, int multiplier) {
    priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;

    for (int i = 0; i < nums.size(); i++) {
      pq.push({nums[i], i});
    }

    for (int i = 0; i < k; i++) {
      auto m = pq.top();
      nums[m[1]] *= multiplier;
      pq.pop();
      pq.push({nums[m[1]], m[1]});
    }

    return nums;
  }
};
