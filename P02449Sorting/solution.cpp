class Solution {
private:
  void solve(vector<int> &nums, vector<int> &target, long long &ans, int rem) {
    vector<int> v1;
    vector<int> v2;

    for (auto n : nums)
      if (n % 2 == rem)
        v1.push_back(n);
    for (auto n : target)
      if (n % 2 == rem)
        v2.push_back(n);

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    for (int i = 0; i < v1.size(); i++) {
      ans += abs(v1[i] - v2[i]) / 2;
    }
  }

public:
  long long makeSimilar(vector<int> &nums, vector<int> &target) {
    long long ans = 0;
    solve(nums, target, ans, 1);
    solve(nums, target, ans, 0);
    return ans / 2;
  }
};
