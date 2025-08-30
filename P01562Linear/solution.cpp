class Solution {
public:
  int findLatestStep(vector<int> &arr, int m) {
    int n = arr.size();
    if (n == m)
      return n;
    vector<int> l(n + 2);
    int ans = -1;
    for (int i = 0; i < n; i++) {
      int c = arr[i], ll = l[c - 1], rr = l[c + 1];
      l[c + rr] = ll + rr + 1;
      l[c - ll] = l[c + rr];
      if (ll == m || rr == m)
        ans = i;
    }
    return ans;
  }
};
