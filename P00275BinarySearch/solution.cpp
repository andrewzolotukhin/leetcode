class Solution {
public:
  int hIndex(vector<int> &citations) {
    int n = citations.size();
    int l = 0, r = n - 1;
    int ans = 0;
    while (l <= r) {
      int mid = (l + r) / 2;
      int cit = citations[mid];
      int papers = n - mid;

      if (cit >= papers) {
        ans = papers;
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
    return ans;
  }
};
