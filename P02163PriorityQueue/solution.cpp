class Solution {
public:
  long long minimumDifference(vector<int> &nums) {
    int n = nums.size() / 3;

    vector<long long> firstHalf(n + 1);
    long long total = 0;
    priority_queue<int> pq;

    for (int i = 0; i < n; i++) {
      total += nums[i];
      pq.push(nums[i]);
    }

    firstHalf[0] = total;

    for (int i = n; i < n * 2; i++) {
      total += nums[i];
      pq.push(nums[i]);
      total -= pq.top();
      pq.pop();
      firstHalf[i - n + 1] = total;
    }

    long long secondHalf = 0;
    priority_queue<int, vector<int>, greater<>> pq2;

    for (int i = n * 3 - 1; i >= n * 2; i--) {
      secondHalf += nums[i];
      pq2.push(nums[i]);
    }

    long long ans = firstHalf[n] - secondHalf;

    for (int i = n * 2 - 1; i >= n; i--) {
      secondHalf += nums[i];
      pq2.push(nums[i]);
      secondHalf -= pq2.top();
      pq2.pop();
      ans = min(ans, firstHalf[i - n] - secondHalf);
    }

    return ans;
  }
};
