class Solution {
public:
  vector<int> processQueries(vector<int> &queries, int m) {
    deque<int> p;
    for (int i = 0; i < m; i++) {
      p.push_back(i + 1);
    }

    vector<int> ans;
    for (auto q : queries) {
      for (int i = 0; i < m; i++) {
        if (p[i] == q) {
          p.erase(p.begin() + i);
          ans.push_back(i);
          break;
        }
      }
      p.push_front(q);
    }
    return ans;
  }
};
