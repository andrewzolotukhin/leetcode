#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> pivotArray(vector<int> &nums, int pivot) {
    vector<int> gr;
    int nextIndex = 0, pc = 0, n = nums.size();

    for (int i = 0; i < n; i++) {
      if (nums[i] == pivot) {
        pc++;
        continue;
      }

      if (nums[i] < pivot) {
        if (i >= nextIndex) {
          nums[nextIndex++] = nums[i];
        }
        continue;
      }

      if (nums[i] > pivot) {
        gr.push_back(nums[i]);
        continue;
      }

      assert(false);
    }

    for (int i = 0; i < pc; i++) {
      nums[nextIndex++] = pivot;
    }

    for (int i = 0; i < gr.size(); i++) {
      nums[nextIndex++] = gr[i];
    }

    return nums;
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  int n, pivot;
  cin >> n >> pivot;
  vector<int> nums(n);

  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  auto result = Solution().pivotArray(nums, pivot);

  for (auto &x : result) {
    cout << x << " ";
  }

  cout << '\n';
}
