class Solution {
private:
  long long solve(vector<int> &a1, vector<int> &a2, long long m) {
    long long ans = 0;

    for (int i = 0, j = a2.size() - 1; i < a1.size(); i++) {
      while (j >= 0 && (long long)a1[i] * a2[j] > m) {
        j--;
      }
      ans += j + 1;
    }

    return ans;
  }

public:
  long long kthSmallestProduct(vector<int> &nums1, vector<int> &nums2,
                               long long k) {
    auto lp = lower_bound(begin(nums1), end(nums1), 0);
    auto rp = lower_bound(begin(nums2), end(nums2), 0);

    vector<int> n1(begin(nums1), lp);
    vector<int> n2(begin(nums2), rp);
    vector<int> p1(lp, end(nums1));
    vector<int> p2(rp, end(nums2));
    vector<int> pos1_r(rbegin(p1), rend(p1)), pos2_r(rbegin(p2), rend(p2));
    vector<int> neg1_r(rbegin(n1), rend(n1)), neg2_r(rbegin(n2), rend(n2));

    long long l = -10000000000, r = 10000000000;
    while (l < r) {
      long long m = (l + r - 1) / 2, cnt = 0;
      if (m >= 0)
        cnt = solve(neg1_r, neg2_r, m) + solve(p1, p2, m) +
              n1.size() * p2.size() + n2.size() * p1.size();
      else
        cnt = solve(pos2_r, n1, m) + solve(pos1_r, n2, m);
      if (cnt < k)
        l = m + 1;
      else
        r = m;
    }
    return l;
  }
};
