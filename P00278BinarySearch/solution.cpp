// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
  int firstBadVersion(int n) {
    uint l = 1, r = n;
    while (l < r) {
      uint mid = l + (r - l) / 2;

      if (!isBadVersion(mid)) {
        l = mid + 1;
      } else {
        r = mid;
      }
    }
    return l;
  }
};
