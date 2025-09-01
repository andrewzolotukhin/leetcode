class Solution {
public:
  double maxAverageRatio(vector<vector<int>> &classes, int extraStudents) {
    priority_queue<pair<double, pair<int, int>>> pq;
    for (auto c : classes) {
      double cc = (double)(c[0] + 1) / (double)(c[1] + 1);
      pair<int, int> t = {c[0], c[1]};
      pq.push({cc - (double)c[0] / (double)c[1], t});
    }

    for (int i = 0; i < extraStudents; i++) {
      auto t = pq.top();
      pq.push({(double)(t.second.first + 2) / (double)(t.second.second + 2) -
                   (double)(t.second.first + 1) / (double)(t.second.second + 1),
               {t.second.first + 1, t.second.second + 1}});
      pq.pop();
    }

    double s = 0;

    while (!pq.empty()) {
      s += (double)pq.top().second.first / (double)pq.top().second.second;
      pq.pop();
    }

    return s / classes.size();
  }
};
