class Solution {
public:
  long long pickGifts(vector<int> &gifts, int k) {
    long long ans = 0LL;

    priority_queue<int> pq;
    for (auto g : gifts) {
      pq.push(g);
      ans += g;
    }

    while (k-- && !pq.empty()) {
      int t = pq.top();
      pq.pop();

      int d = sqrt(t);

      ans -= t - d;
      pq.push(d);
    }

    return ans;
  }
};
