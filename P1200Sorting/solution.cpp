class Solution {
public:
  vector<vector<int>> minimumAbsDifference(vector<int> &arr) {
    auto ans = vector<vector<int>>();
    sort(arr.begin(), arr.end());
    int mv = INT_MAX;
    for (int i = arr.size() - 1; i > 0; i--) {
      if (arr[i] - arr[i - 1] < mv) {
        mv = arr[i] - arr[i - 1];
        ans.clear();
      }
      if (arr[i] - arr[i - 1] == mv) {
        auto a = vector<int>();
        a.push_back(arr[i - 1]);
        a.push_back(arr[i]);
        ans.push_back(a);
      }
    }
    sort(ans.begin(), ans.end());
    return ans;
  }
};
