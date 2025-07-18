class Solution {
public:
  int minSetSize(vector<int> &arr) {
    unordered_map<int, int> freq;
    for (auto v : arr)
      freq[v]++;

    priority_queue<int> e;
    for (auto [k, v] : freq)
      e.push(v);

    int h = arr.size() / 2;

    int ans = 0;
    int s = 0;
    int i = 0;

    while (!e.empty() && s < h) {
      s += e.top();
      e.pop();
      ans++;
    }

    return ans;
  }
};
