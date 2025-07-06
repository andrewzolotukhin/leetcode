class Solution {
public:
  int findKthPositive(vector<int> &arr, int k) {
    int n = arr.size();

    int l = 0, r = n;

    while (l < r) {
      int mid = l + (r - l) / 2;

      if (arr[mid] - 1 - mid < k) {
        l = mid + 1;
      } else {
        r = mid;
      }
    }
    return l + k;
  }
};
