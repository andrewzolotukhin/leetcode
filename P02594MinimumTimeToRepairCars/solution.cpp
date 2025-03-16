class Solution {
public:
  long long repairCars(vector<int> &ranks, int cars) {
    unordered_map<int, int> cnt;

    for (auto r : ranks)
      cnt[r]++;

    auto cmp = [&](vector<long long> &a, vector<long long> &b) -> bool {
      return a[0] > b[0];
    };

    priority_queue<vector<long long>, vector<vector<long long>>, decltype(cmp)>
        hp(cmp);

    for (auto [r, c] : cnt) {
      hp.push({r, r, 1, c});
    }

    long long res = 0;

    while (cars > 0) {
      vector<long long> c = hp.top();
      hp.pop();

      res = c[0];
      long long r = c[1];
      long long repairedCars = c[2];
      long long mcnt = c[3];

      cars -= mcnt;

      repairedCars++;

      hp.push({r * repairedCars * repairedCars, r, repairedCars, mcnt});
    }

    return res;
  }
};
