class Solution {
public:
  int minimumCost(vector<int> &nums) {
    priority_queue<int, vector<int>, greater<>> pq;
    for (int i = 1; i < nums.size(); i++)
      pq.push(nums[i]);
    int ans = nums[0];
    ans += pq.top();
    pq.pop();
    ans += pq.top();
    pq.pop();
    return ans;
  }
};
