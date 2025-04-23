class Solution {
private:
  int dsum(int n) {
    int ans = 0;
    while (n) {
      ans += n % 10;
      n /= 10;
    }
    return ans;
  }

public:
  int countLargestGroup(int n) {
    unordered_map<int, int> freq;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      int r = dsum(i);
      freq[r]++;
    }
    priority_queue<int> pq;
    for (auto [k, v] : freq)
      pq.push(v);

    int f = pq.top();
    while (!pq.empty() && pq.top() == f) {
      pq.pop();
      ans++;
    }
    return ans;
  }
};
