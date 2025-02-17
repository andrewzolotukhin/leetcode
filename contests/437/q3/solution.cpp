#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool maxSubstringLength(string s, int k) {
    if (k == 0)
      return true;

    vector<pair<int, int>> minMax(26, {-1, -1});

    for (int i = 0; i < s.size(); i++) {
      int index = s[i] - 'a';
      minMax[index].first =
          minMax[index].first == -1 ? i : min(minMax[index].first, i);
      minMax[index].second = max(minMax[index].second, i);
    }

    vector<pair<int, int>> candidates;

    int n = s.size();

    for (int i = 0; i < n; i++) {
      int index = s[i] - 'a';
      if (minMax[index].first != i) {
        continue;
      }

      int start = i;
      int end = minMax[index].second;

      for (int j = i + 1; j <= end; j++) {
        int index2 = s[j] - 'a';
        if (minMax[index2].first < start) {
          start = minMax[index2].first;
          end = max(end, minMax[index2].second);
          j = start;
        }
        if (minMax[index2].second > end) {
          end = minMax[index2].second;
        }
      }

      if (!(start == 0 && end == n - 1)) {
        candidates.push_back({start, end});
      }
    }

    sort(candidates.begin(), candidates.end(),
         [&](pair<int, int> a, pair<int, int> b) {
           return a.second < b.second;
         });

    int found = 0;
    int last = -1;

    for (auto candidate : candidates) {
      if (candidate.first > last) {
        found++;
        last = candidate.second;
      }
    }

    return found >= k;
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  int k;
  string s;
  cin >> k >> s;

  cout << (Solution().maxSubstringLength(s, k) ? "yes" : "no") << '\n';
}
