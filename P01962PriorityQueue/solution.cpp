class Solution {
public:
  int minStoneSum(vector<int> &piles, int k) {
    priority_queue<int> pq;
    int total = 0;
    for (auto p : piles) {
      pq.push(p);
      total += p;
    }

    while (k--) {
      auto t = pq.top();
      pq.pop();
      total -= t / 2;
      pq.push(t - t / 2);
    }

    return total;
  }
};
