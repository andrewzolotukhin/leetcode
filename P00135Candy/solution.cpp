class Solution {
public:
  int candy(vector<int> &ratings) {
    int n = ratings.size();
    vector<int> res(n, 1);

    auto comp = [&](int a, int &b) { return ratings[a] > ratings[b]; };
    priority_queue<int, vector<int>, decltype(comp)> pq(comp);
    for (int i = 0; i < n; i++)
      pq.push(i);

    while (!pq.empty()) {
      auto index = pq.top();
      pq.pop();
      if (index > 0 && ratings[index - 1] < ratings[index]) {
        res[index] = res[index - 1] + 1;
      }
      if (index < n - 1 && ratings[index] > ratings[index + 1]) {
        if (res[index + 1] + 1 > res[index]) {
          res[index] = res[index + 1] + 1;
        }
      }
    }

    int ans = 0;
    for (auto v : res)
      ans += v;
    return ans;
  }
};
