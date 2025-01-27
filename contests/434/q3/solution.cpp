#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxFrequency(vector<int> &nums, int k) {

    int maxFreq = 0;
    int currFreq = 0;

    int c = count(nums.begin(), nums.end(), k);

    int n = nums.size();
    vector<int> freq(51, 0);

    // as nums[i] is >= 1 and <= 50
    // we can just iterate over all possible values
    for (int i = 0; i < n; i++) {
      freq[nums[i]]++;

      for (int j = 1; j <= 50; j++) {
        // TODO
      }
    }

    return maxFreq;
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  int n, m;
  cin >> n >> m;
  vector<int> nums(n);

  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  Solution sol;

  cout << sol.maxFrequency(nums, m) << '\n';
}
