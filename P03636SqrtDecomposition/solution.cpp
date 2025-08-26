class Solution {
public:
  vector<int> subarrayMajority(vector<int> &nums,
                               vector<vector<int>> &queries) {
    int C = int(sqrt(nums.size()));

    int c = nums.size() / C + 1;

    vector<array<int, 4>> q;

    int i = 0;
    for (auto &qq : queries) {
      q.push_back({qq[0], qq[1], qq[2], i});
      i++;
    }

    vector<int> ans(queries.size());
    unordered_map<int, int> freqMap(nums.size());
    vector<set<int>> freqs(nums.size() + 1);

    int maxFreq = 0;

    int bs = sqrt(nums.size());

    sort(q.begin(), q.end(), [&](auto &a, auto &b) {
      pair<int, int> l = {a[0] / bs, (a[0] / bs & 1) ? -a[1] : a[1]};
      pair<int, int> r = {b[0] / bs, (a[0] / bs & 1) ? -b[1] : b[1]};
      return l < r;
    });

    auto add = [&](int index) {
      freqs[freqMap[nums[index]]].erase(nums[index]);
      freqs[++freqMap[nums[index]]].insert(nums[index]);
      if (freqMap[nums[index]] > maxFreq)
        maxFreq = freqMap[nums[index]];
    };

    auto remove = [&](int index) {
      freqs[freqMap[nums[index]]].erase(nums[index]);
      int r = --freqMap[nums[index]];
      if (r > 0) {
        freqs[r].insert(nums[index]);
      }

      if (maxFreq > 0 && freqs[maxFreq].empty())
        maxFreq--;
    };

    auto get = [&](const array<int, 4> &q) {
      if (maxFreq < q[2])
        return -1;
      return *freqs[maxFreq].begin();
    };

    int cl = 0, cr = -1;

    for (auto &qq : q) {
      while (cr < qq[1]) {
        cr++;
        add(cr);
      }
      while (cl > qq[0]) {
        cl--;
        add(cl);
      }
      while (cr > qq[1]) {
        remove(cr);
        cr--;
      }
      while (cl < qq[0]) {
        remove(cl);
        cl++;
      }

      ans[qq[3]] = get(qq);
    }

    return ans;
  }
};
