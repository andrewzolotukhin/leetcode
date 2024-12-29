#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> maxSumOfThreeSubarrays(vector<int> &nums, int k) {
    int n = nums.size();
    vector<int> prefix = vector<int>(n + 1, 0);

    if (3 * k > nums.size()) {
      return {};
    }

    for (int i = 0; i < n; i++) {
      prefix[i + 1] = prefix[i] + nums[i];
    }

    vector<pair<int, int>> ks;

    for (int i = k; i <= n; i++) {
      ks.push_back({prefix[i] - prefix[i - k], i - k});
    }

    sort(ks.begin(), ks.end(), [&](pair<int, int> &a, pair<int, int> &b) {
      if (a.first == b.first) {
        return a.second < b.second;
      }
      return a.first > b.first;
    });

    auto isOverlap = [&](int as, int ae, int bs, int be) {
      return as <= bs ? ((as <= bs && ae >= bs && ae <= be) ||
                         (as <= bs && be <= ae))
                      : ((bs <= as && be >= as && be <= ae) ||
                         (bs <= as && ae <= be));
    };

    int limit = 0;
    vector<pair<int, int>> groups;
    int gs = 0;
    int ge = 0;
    int ss = ks[0].second;
    int se = ks[0].second + k - 1;
    for (int i = 1; i < ks.size(); i++) {
      // cout << ks[i].first << " " << ks[i].second << " "
      //      << (ks[i].second + k - 1) << endl;
      if (isOverlap(ss, se, ks[i].second, ks[i].second + k - 1)) {
        ss = min(ss, ks[i].second);
        se = max(se, ks[i].second + k - 1);
        ge = i;
      } else {
        groups.push_back({gs, ge});
        ss = ks[i].second;
        se = ks[i].second + k - 1;
        gs = i;
        ge = i;
      }
      limit++;
      if (groups.size() >= 3) {
        break;
      }
    }

    groups.push_back({gs, ge});

    vector<int> res;
    int maxSum = INT_MIN;

    vector<int> maxElements = vector<int>(ks.size(), 0);
    maxElements[ks.size() - 1] = 0;
    for (int i = ks.size() - 2; i >= 0; i--) {
      maxElements[i] = max(maxElements[i + 1], ks[i + 1].first);
    }

    // for (auto kkk : ks) {
    //   cout << kkk.first << " ";
    // }
    // cout << endl;
    //
    // for (auto kkk : maxElements) {
    //   cout << kkk << " ";
    // }
    // cout << endl;
    //
    for (auto group : groups) {
      cout << "Group: " << group.first << " " << group.second << endl;
    }

    for (int i = groups[0].first; i <= groups[0].second; i++) {
      for (int j = i + 1; j < ks.size() - 1; j++) {
        if (ks[i].first + ks[j].first + maxElements[j] < maxSum)
          continue;
        for (int r = j + 1; r < ks.size(); r++) {
          if ((!isOverlap(ks[i].second, ks[i].second + k - 1, ks[j].second,
                          ks[j].second + k - 1)) &&
              (!isOverlap(ks[i].second, ks[i].second + k - 1, ks[r].second,
                          ks[r].second + k - 1)) &&
              (!isOverlap(ks[j].second, ks[j].second + k - 1, ks[r].second,
                          ks[r].second + k - 1))) {
            int sum = ks[i].first + ks[j].first + ks[r].first;
            if (sum > maxSum) {
              maxSum = sum;
              res.clear();
              res.push_back(ks[i].second);
              res.push_back(ks[j].second);
              res.push_back(ks[r].second);
            }
          }
        }
      }
    }

    // for (int i = 0; i < limit; i++) {
    //   for (int j = i + 1; j <= limit; j++) {
    //     for (int r = j + 1; r <= limit; r++) {
    //       if ((!isOverlap(ks[i].second, ks[i].second + k - 1, ks[j].second,
    //                       ks[j].second + k - 1)) &&
    //           (!isOverlap(ks[i].second, ks[i].second + k - 1, ks[r].second,
    //                       ks[r].second + k - 1)) &&
    //           (!isOverlap(ks[j].second, ks[j].second + k - 1, ks[r].second,
    //                       ks[r].second + k - 1))) {
    //         int sum = ks[i].first + ks[j].first + ks[r].first;
    //         if (sum > maxSum) {
    //           maxSum = sum;
    //           res.clear();
    //           res.push_back(ks[i].second);
    //           res.push_back(ks[j].second);
    //           res.push_back(ks[r].second);
    //         }
    //       }
    //     }
    //   }
    // }

    sort(res.begin(), res.end());
    return res;
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  int n, k;
  cin >> n >> k;
  vector<int> nums;

  while (n--) {
    int l;
    cin >> l;
    nums.push_back(l);
  }

  Solution s;
  auto res = s.maxSumOfThreeSubarrays(nums, k);

  for (auto rr : res) {
    cout << rr << " ";
  }
  cout << '\n';
}
