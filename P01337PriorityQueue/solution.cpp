class Solution {
public:
  vector<int> kWeakestRows(vector<vector<int>> &mat, int k) {
    auto comp = [&](pair<int, int> &a, pair<int, int> &b) {
      if (a.first == b.first) {
        return a.second > b.second;
      }
      return a.first > b.first;
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> pq(
        comp);
    int i = 0;
    for (auto r : mat) {
      int c = 0;
      for (auto v : r) {
        if (v) {
          c++;
        } else {
          break;
        }
      }
      pq.push({c, i++});
    }

    vector<int> ans;
    for (int j = 0; j < k; j++) {
      ans.push_back(pq.top().second);
      pq.pop();
    }

    return ans;
  }
};
