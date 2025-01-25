#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> lexicographicallySmallestArray(vector<int> &nums, int limit) {
    int n = nums.size();
    unordered_map<int, int> numToGroup;
    unordered_map<int, vector<int>> groupToNums;
    auto sorted = vector<int>(nums);
    sort(sorted.begin(), sorted.end());
    int currentGroup = 0;

    numToGroup[sorted[0]] = currentGroup;
    groupToNums[currentGroup] = vector<int>();
    groupToNums[currentGroup].push_back(sorted[0]);

    for (int i = 1; i < n; i++) {
      if (abs(sorted[i] - sorted[i - 1]) > limit) {
        currentGroup++;
      }
      numToGroup[sorted[i]] = currentGroup;
      if (!groupToNums.count(currentGroup)) {
        groupToNums[currentGroup] = vector<int>();
      }
      groupToNums[currentGroup].push_back(sorted[i]);
    }

    for (int i = 0; i < n; i++) {
      int group = numToGroup[nums[i]];
      nums[i] = groupToNums[group].front();
      groupToNums[group].erase(groupToNums[group].begin());
    }

    return nums;
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  int n, m;
  cin >> n >> m;

  vector<int> nums;

  while (n--) {
    int num;
    cin >> num;
    nums.push_back(num);
  }

  Solution solution;

  auto result = solution.lexicographicallySmallestArray(nums, m);

  for (int i = 0; i < result.size(); i++) {
    cout << result[i] << "\n";
  }
}
