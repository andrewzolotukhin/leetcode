class Solution {
public:
  long long interchangeableRectangles(vector<vector<int>> &rectangles) {
    unordered_map<long long, long long> freq;
    for (auto &r : rectangles) {
      long long g = gcd(r[0], r[1]);
      long long w = r[0] / g, h = r[1] / g;
      long long k = (w << 20) | h;
      freq[k]++;
    }

    long long ans = 0LL;
    for (auto &[k, v] : freq) {
      ans += v * (v - 1) / 2;
    }

    return ans;
  }
};
