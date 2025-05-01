class Solution {
private:
  int isGood(int k, vector<int> &tasks, vector<int> &workers, int pills,
             int strength) {
    int n = tasks.size(), m = workers.size();

    multiset<int> goods;

    for (int i = m - k; i < m; i++) {
      goods.insert(workers[i]);
    }

    for (int i = k - 1; i >= 0; i--) {
      auto last = prev(goods.end());
      if (*last >= tasks[i]) {
        goods.erase(last);
      } else {
        if (pills == 0)
          return false;
        auto fulfilled = goods.lower_bound(tasks[i] - strength);
        if (fulfilled == goods.end())
          return false;
        pills--;
        goods.erase(fulfilled);
      }
    }
    return true;
  }

public:
  int maxTaskAssign(vector<int> &tasks, vector<int> &workers, int pills,
                    int strength) {
    sort(tasks.begin(), tasks.end());
    sort(workers.begin(), workers.end());

    int n = tasks.size(), m = workers.size();

    int l = 1, r = min(n, m);
    int ans = 0;

    while (l <= r) {
      int m = (l + r) / 2;

      if (isGood(m, tasks, workers, pills, strength)) {
        l = m + 1;
        ans = m;
      } else {
        r = m - 1;
      }
    }

    return ans;
  }
};
