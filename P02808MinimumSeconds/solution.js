class Solution {
  public:
    int minimumSeconds(vector<int>& nums) {
  map < int, int > freq;
        int m = 0;
        int n = nums.size();
  for (auto v: nums) {
    freq[v]++;
  }
  if (freq.size() == 1) return 0;
  if (freq.size() == n) return n / 2;

        int ans = INT_MAX;
        int minL = INT_MAX;
  for (auto[v, f]: freq) {
    if (f == 1) continue;
            int l = 0;
            int maxL = 0;
    for (int j = -1; j < 2 * n + 1; j++) {
      if (nums[(j + n) % n] == v) {
        maxL = max(maxL, l);
        //cout << v << ": " << l << '\n';
        l = 0;
      } else {
        l++;
      }
    }
    minL = min(minL, maxL);
  }

  return (minL + 1) / 2;
}
};
